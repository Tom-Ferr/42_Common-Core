
import './mail.css'
import axios from 'axios';
import { useState, useEffect, useMemo } from "react";
import io, { Socket } from 'socket.io-client'
import { useNavigate } from "react-router-dom"

const Mail = () => {

    const[user, setUser] = useState('')
    const[mailBox, setMailBox] = useState([])
    const[contacts, setContacts] = useState([])
    const[selectedUser, setSelectedUser] = useState([])
    const[input, setInput] = useState('')
    const[isNewContact, setIsNewContact] = useState(false)
    const[newContact, setNewContact] = useState('')

    const navigate = useNavigate()
    const socket: Socket = useMemo( () => io('http://localhost:3000/chatroom', { autoConnect: false }), [])

    const loadMail = async () => {
        let array = []
        if(user.mail.length){
            setIsNewContact(false)
            setContacts([])
            if(user.mail[0].from != user.name)
                setSelectedUser(user.mail[0].from)
            else
                setSelectedUser(user.mail[0].to)
            user.mail.forEach(element => {
                if(element.from != user.name && !array.includes(element.from))
                    array = [...array, element.from]
                else if(element.to != user.name && !array.includes(element.to))
                    array = [...array, element.to]
            });
            setContacts(array)
            setMailBox(user.mail)
        }
        else{
            setIsNewContact(true)
            setSelectedUser('new contact')
        }
    };

    const loadInfo = async () => {

        await axios.get("http://localhost:3000/authentication", {withCredentials: true})
        .then(response => {
            if(response.data.name)
                setUser(response.data)
        })
        .catch(error => {
            navigate('/')
        })
    };

    useEffect( () => loadInfo(), [])
    useEffect( () => {
                if(user.name){
                    loadMail()
                    socket.auth = {username: user.name, userID: user.id, sessionID: localStorage.getItem("sessionID")} ;
                    socket.connect();
                }
                else if(user == null)
                    navigate('/')
    }, [user])

    useEffect( () => {
        socket.on("session", ({ sessionID, userID }) => {
            localStorage.setItem("sessionID", sessionID);
          });
        socket.on('receive_private-message', (content) => { 
            setMailBox(content)
        })
       
    }, [socket])

    const displayContacts = () => {
        return contacts.map( (contact, index) => (<p key={index} onClick={ () => {setSelectedUser(contact); setIsNewContact(false)}}> {contact} </p>) )
    }


    const displayMessages = () => {
        if(mailBox.length)
            return mailBox.map( (message, index) => {
                if (message.from === selectedUser || message.to === selectedUser)
                    return (<p key={index} >{message.message}</p>)
            } )
    }

    const sendPrivateMessage = () => {
        let destiny = selectedUser
        if(isNewContact){
            destiny = newContact
            if(!contacts.includes(destiny))
                setContacts([...contacts, destiny])
                setIsNewContact(false)
            
        }
        socket.emit('private-message', {from: user.name, to: destiny, message: input, sender_id: user.id})
        setMailBox([...mailBox, {from: user.name, to: destiny, message: input}])
        setInput('')
        setSelectedUser(destiny)
    }

    return(
        <>
        <div className='users'>
            <p onClick={ () => {setSelectedUser('new contact'); setIsNewContact(true)} }> new contact</p>
            {displayContacts()}
            
        </div>

        <div className='messages'>
            {!isNewContact && <h1 className='title'>
                    Your chat with {selectedUser}
            </h1>}
            <div className='chatBox'>
                {displayMessages()}
            </div>

            <div className='send'>
                {isNewContact && <div>
                    to: 
                    <input
                    type="text"
                    onChange={event => setNewContact(event.target.value)}
                    />
                    <br></br>
                </div>}  
                <input
                    type="text"
                    value={input}
                    onChange={event => setInput(event.target.value)}
                />    
                <input
                    type="button"
                    onClick={sendPrivateMessage}
                    value="Send!"
                />    
            </div>     
        </div>
        </>

    );
}

export default Mail