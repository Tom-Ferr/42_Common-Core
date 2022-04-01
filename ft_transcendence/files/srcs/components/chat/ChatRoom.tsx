
import io, { Socket } from 'socket.io-client'
import { useState, useEffect, useMemo, useLocation } from "react";
import { useSearchParams, useNavigate } from 'react-router-dom';
import Popup from './PopUp'
import './popup.css'
import axios from 'axios'

interface Messages{
    name: string;
    message: string
}

export const ChatRoom = () =>{

    const [searchParams] = useSearchParams();
    const navigate = useNavigate()
    const name = searchParams.get('name')
    const room = searchParams.get('room_id')
    const [messages, setMessages] = useState<Messages[]>([])

    const [isOpen, setIsOpen] = useState(false);
 
    const togglePopup = () => {
    setIsOpen(!isOpen);
  }

    const socket: Socket = useMemo( () => io('http://localhost:3000/chatroom', {query: {name: name}}), [])

    useEffect( () => {
        socket.on('connect', () => {
            socket.emit('join', {room_id: room})
        })
    }, [])

    useEffect( () => {
        socket.on('receive_message', (content: any) => setMessages(prevState => [...prevState, content]))
        socket.on('receive_invitation', (content: any) => { setHost(content.host) ;  togglePopup() })
        socket.on('invitation_was_accepted', (content: any) => navigate(`/pong?name=${name}&room_id=${content.game_room}`))
        socket.on('invitation_was_declined', (content: any) => alert('Your invitation was declined'))
    }, [socket])

    const [input, setInput] = useState("")
    const handleChange = (event) => {
        setInput(event.target.value)    
    }

    const handleClick = async () => {
        socket.emit('send_message', {name: name, room_id: room, message: input})
        setInput('')
    }
    const [guest, setGuest] = useState("")
    const [host, setHost] = useState("")
    
    const handleInvitation = (event) => {
        setGuest(event.target.value)    
    }

    const handleInviteClick = async () => {
        socket.emit('send_invitation', {host: name, room_id: room, guest: guest})
        setGuest('')
        
    }

    const handleAcceptInvitation = async () => {
        togglePopup()
        await axios.post('http://localhost:3000/game',{p1: name, p2: host} , {withCredentials: true})
        .then(response => {
            socket.emit('invitation_accepted', {game_room: response.data.id, host: host, guest: name})
            navigate(`/pong?name=${name}&room_id=${response.data.id}`)
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const handleDeclineInvitation = () => {
        socket.emit('invitation_declined', { host: host, guest: name })
        togglePopup()
    }

    return(
        <div>

            <ul>

            {messages.map((messages, key) => (<p key={key}>{messages.name} - {messages.message}</p>)) }

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
            <br></br>
            <input
                type="text"
                onChange={handleInvitation}
                value={guest}
            />
            <input
                type="button"
                onClick={handleInviteClick}
                value="send invitation"
            /> 
            {isOpen && <Popup
      content={<>
        <b>You have received an invitation</b>
        <p>{host} wants to play Pong with you </p>
        <input type="button" onClick={handleAcceptInvitation} value='Accept'/>
        <input type="button" onClick={handleDeclineInvitation} value='Decline'/>
      </>}
      handleClose={togglePopup}
    />}
        </div>
    )
}