/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChatRoom.tsx                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:23 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:27:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


import io, { Socket } from 'socket.io-client'
import { useState, useEffect, useMemo, useLocation } from "react";
import { useSearchParams, useNavigate } from 'react-router-dom';
import Popup from './PopUp'
import './popup.css'
import axios from 'axios'
import './chatroom.css'

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
    const [isSelected, setIsSelected] = useState(false);
    const [input, setInput] = useState("")
    const [host, setHost] = useState("")
    const [userslist, setUsersList] = useState("")
    const [selectedUser, setSelectedUser] = useState("")

    const socket: Socket = useMemo( () => io('http://localhost:3000/chatroom', {query: {name: name}}), [])

    useEffect( () => {
        socket.on('connect', () => {
            socket.emit('join', {room_id: room})
        })
    }, [])

    useEffect( () => {
        socket.on('receive_message', (content: any) => setMessages(prevState => [...prevState, content]))
        socket.on('receive_invitation', (content: any) => { setHost(content.host) ;  setIsOpen(!isOpen); })
        socket.on('invitation_was_accepted', (content: any) => navigate(`/pong?name=${name}&room_id=${content.game_room}`))
        socket.on('invitation_was_declined', (content: any) => alert('Your invitation was declined'))
    }, [socket])

    const handleClick = async () => {
        socket.emit('send_message', {name: name, room_id: room, message: input})
        setInput('')
    }

    const handleInviteClick = async () => {
        socket.emit('send_invitation', {host: name, room_id: room, guest: selectedUser})
    }

    const handleAcceptInvitation = async () => {
        setIsOpen(!isOpen);
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
        setIsOpen(!isOpen);
    }
    const clickOnUser = (clickedUser) => {
        // if(user.name != clickedUser)
        setSelectedUser(clickedUser);setIsSelected(true)
    }

    return(
        <>
        <div className='chat'>

            <ul className='chatBox'>
                {messages.map((messages, key) => (<p key={key}><span style={{cursor: 'pointer'}} onClick={() => clickOnUser(messages.name)}>{messages.name}</span> - {messages.message}</p>)) }
            </ul>

            <div className='send'>
                <input
                    type="text"
                    onChange={(event) => setInput(event.target.value)}
                    value={input}
                />
                <input
                    type="button"
                    onClick={handleClick}
                    value="send"
                /> 
            </div>
        
            {isSelected && <Popup
                content={<>
                    <li style={{cursor: 'pointer'}} onClick={() => navigate(`/profile?name=${selectedUser}`)}>View {selectedUser} Profile</li>
                    <br></br>
                    <li style={{cursor: 'pointer'}} onClick={handleInviteClick}>Invite {selectedUser} to a pong match </li>
                </>}
                handleClose={() => setIsOpen(!isSelected)}
            />}
            
            {isOpen && <Popup
                content={<>
                    <b>You have received an invitation</b>
                    <p>{host} wants to play Pong with you </p>
                    <input type="button" onClick={handleAcceptInvitation} value='Accept'/>
                    <input type="button" onClick={handleDeclineInvitation} value='Decline'/>
                </>}
                handleClose={() => setIsOpen(!isOpen)}
            />}
        </div>
        </>
    )
}