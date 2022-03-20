
import io, { Socket } from 'socket.io-client'
import { useState, useEffect, useMemo, useLocation } from "react";
import { useSearchParams } from 'react-router-dom';

interface Messages{
    name: string;
    message: string
}

export const Chat = () =>{

    const [searchParams] = useSearchParams();
    const name = searchParams.get('name')
    const [messages, setMessages] = useState<Messages[]>([])

    const socket: Socket = useMemo( () => io('http://localhost:3000'), [])

    useEffect( () => {
        socket.on('connect', () => console.log("conectado"))
        socket.on('receive_message', (content: any) => setMessages(prevState => [...prevState, content]))
    }, [socket])

    const [input, setInput] = useState("")
    const handleChange = (event) => {
        setInput(event.target.value)    
    }

    const handleClick = async () => {
        socket.emit('send_message', {name: name, message: input})
        setInput('')
    }

     


    return(
        <div>
            <ul>

            {messages.map((messages, key) => (<li key={key}>{messages.name} - {messages.message}</li>)) }

            </ul>


             <input
            type="text"
            onChange={handleChange}
            value={input}
        />
        <input
            type="button"
            onClick={handleClick}
            value="send"
        /> 
        </div>
    )
}