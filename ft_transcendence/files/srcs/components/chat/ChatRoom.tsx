/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChatRoom.tsx                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:23 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/06 20:17:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


import io, { Socket } from 'socket.io-client'
import { useState, useEffect, useMemo, useLocation } from "react";
import { useSearchParams, useNavigate } from 'react-router-dom';
import Popup from '../PopUp/PopUp'
import axios from 'axios'
import './chatroom.css'

interface Messages{
    name: string;
    message: string
}

export const ChatRoom = () =>{

    const [searchParams] = useSearchParams();
    const navigate = useNavigate()
    const room = searchParams.get('room_id')
    
    const [messages, setMessages] = useState<Messages[]>([])
    const [isOpen, setIsOpen] = useState(false);
    const [isSelected, setIsSelected] = useState(false);
    const [isPassWin, setIsPassWin] = useState(false);
    const [input, setInput] = useState("")
    const [host, setHost] = useState("")
    const [user, setUser] = useState("")
    const [owner, setOwner] = useState("")
    const [selectedUser, setSelectedUser] = useState("")
    const [banlist, setBanList] = useState([])
    const [admlist, setAdmList] = useState([])
    const [connectedlist, setConnectedList] = useState([])
    const [newpassword, setNewPassword] = useState('')

    const socket: Socket = useMemo( () => io('http://localhost:3000/chatroom', {query: {room_id: room}, autoConnect: false}), [])

    const loadInfo = async () => {

        await axios.get("http://localhost:3000/authentication", {withCredentials: true})
        .then(response => {
            if(response.data.name)
                setUser(response.data)
        })
        .catch(error => {
            navigate('/')
        })
    }
    const loadChatInfo = async () => {

        await axios.get(`http://localhost:3000/chat/${room}`, {withCredentials: true})
        .then(response => {
            if(response.data.id){
                setBanList(response.data.ban_list)
                setAdmList(response.data.adms)
                setOwner(response.data.owner)
            }
        })
        .catch(error => {
            navigate('/')
        })
    }

    useEffect( async () => {
        await loadChatInfo()
        await loadInfo()
    }, [])

    useEffect( () => {
        if(user){
            if(!banlist.includes(user.name)){
                socket.auth = {username: user.name} ;
                socket.connect();
                socket.on('connect', () => {
                    socket.emit('join', {room_id: room})
                })
            }
            else
                navigate('/logged')
        }
    }, [user])

    useEffect( () => {
        socket.on('receive_connected', (content: any) => setConnectedList(content))
        socket.on('receive_message', (content: any) => setMessages(prevState => [...prevState, content]))
        socket.on('receive_invitation', (content: any) => { setHost(content.host) ;  setIsOpen(!isOpen); })
        socket.on('invitation_was_accepted', (content: any) => navigate(`/pong?name=${user.name}&room_id=${content.game_room}`))
        socket.on('invitation_was_declined', (content: any) => alert('Your invitation was declined'))
        socket.on('ban-updated', (content: any) => {setBanList(content); setIsSelected(!setIsSelected)})
        socket.on('adm-updated', (content: any) => {setAdmList(content); setIsSelected(!setIsSelected)})
    }, [socket])

    const handleClick = async () => {
        socket.emit('send_message', {name: user.name, room_id: room, message: input})
        setInput('')
    }

    const handleInviteClick = async () => {
        socket.emit('send_invitation', {host: user.name, room_id: room, guest: selectedUser})
    }

    const handleAcceptInvitation = async () => {
        setIsOpen(!isOpen);
        await axios.post('http://localhost:3000/game',{p1: user.name, p2: host} , {withCredentials: true})
        .then(response => {
            socket.emit('invitation_accepted', {game_room: response.data.id, host: host, guest: user.name})
            navigate(`/pong?name=${user.name}&room_id=${response.data.id}`)
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const handleDeclineInvitation = () => {
        socket.emit('invitation_declined', { host: host, guest: user.name })
        setIsOpen(!isOpen);
    }

    const updateChat = async () => {
        let status = 'protected'
        if(!newpassword)
            status = 'public'
        axios.put('http://localhost:3000/chat',{id: room, password: newpassword, status: status}, { withCredentials: true})
        .catch(error => alert(error.data))
        setIsPassWin(!isPassWin)
    }

    const clickOnUser = (clickedUser) => {
        if(user.name != clickedUser){
            setSelectedUser(clickedUser);
            setIsSelected(true)
        }
    }
  
    const checkOwner = () => {
        if (owner === (user.name))
            return (<><li style={{cursor: 'pointer'}} onClick={() => {setIsSelected(false);setIsPassWin(!isPassWin)}} >Set password </li><br></br></>)
        else
            return(<></>)
    }

    const setAdm = ( ) => {

        socket.emit('set-adm', {target: selectedUser, room_id: room})
    }

    const ban = () => {

        socket.emit('ban-user', {target: selectedUser, room_id: room})
    }

    const unBan = () => {
        
        socket.emit('unban-user', {target: selectedUser, room_id: room})
    }

    const mute = (minutes) => {
        minutes *= 60000
        socket.emit('mute-user', {target: selectedUser, room_id: room, time: minutes})
    }

    const banStatus = () => {
        if(banlist.includes(selectedUser))
            return(<><br></br><li style={{cursor: 'pointer'}} onClick={unBan} > Unban {selectedUser} from this room</li></>)
        return (<><br></br><li style={{cursor: 'pointer'}} onClick={ban} > Ban {selectedUser} from this room</li></>)
    }

    const admStatus = () => {
        if(!admlist.includes(selectedUser))
            return (<><br></br><li style={{cursor: 'pointer'}} onClick={setAdm} >Set {selectedUser} as Administrator</li></>)
        return(<></>)
    }


    const checkAdm = () => {

        if (admlist.includes(user.name))
            return true
        return false
    }

    const displayBannedUsers = () => {
            return banlist.map( (banned, index) => (<p key={index} style={{cursor: 'pointer'}} onClick={ () => {clickOnUser(banned)}}> {banned} </p>) )
    }

    const displayConnectedUsers = () => {
            return connectedlist.map( (connected, index) => (<p key={index} style={{cursor: 'pointer'}} onClick={ () => {clickOnUser(connected)}}> {connected} </p>) )
    }

    return(
        <>
        <div className='list'>
            {checkOwner()}
            Connected Users:
            {displayConnectedUsers()}
            <br></br>
            {
                checkAdm() &&
                <>Banned Users:
                {displayBannedUsers()}
                </>
            }
        </div>
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
                    {checkAdm() && <>
                        <br></br>
                        <li> Mute {selectedUser} for: 
                            <span style={{cursor: 'pointer'}} onClick={() => mute(15)}> 15 Minutes,</span>
                            <span style={{cursor: 'pointer'}} onClick={() => mute(30)}> 30 Minutes,</span>
                            <span style={{cursor: 'pointer'}} onClick={() => mute(60)}> 1 Hour</span>
                        </li>
                        {admStatus()}
                        {banStatus()}
                    </>}
                </>}
                handleClose={() => setIsSelected(!isSelected)}
            />}
            
            {isOpen && <Popup
                content={<>
                    <b>You have received an invitation</b>
                    <p>{host} wants to play Pong with you </p>
                    <input type="button" onClick={handleAcceptInvitation} value='Accept'/>
                    <input type="button" onClick={handleDeclineInvitation} value='Decline'/>
                </>}
                handleClose={() => {setIsOpen(!isOpen); handleDeclineInvitation() }}
            />}
            {isPassWin && <Popup
                content={<>
                    <b>Set a New Password for this chat</b>
                    <input type="password" onChange={(event) => setNewPassword(event.target.value)} value={newpassword}/>
                    <input type="button" onClick={updateChat} value='Set'/>
                </>}
                handleClose={() => {setIsPassWin(!isPassWin)}}
            />}
        </div>
        </>
    )
}