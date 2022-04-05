/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChatRoom.tsx                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:23 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/05 20:54:58 by tde-cama         ###   ########.fr       */
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
    const [input, setInput] = useState("")
    const [host, setHost] = useState("")
    const [user, setUser] = useState("")
    const [chatInfo, setChatInfo] = useState("")
    const [selectedUser, setSelectedUser] = useState("")

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
            if(response.data.id)
                setChatInfo(response.data)
        })
        .catch(error => {
            navigate('/')
        })
    }

    useEffect( async () => {
        await loadChatInfo()
        await loadInfo()
        socket.auth = {username: user.name} ;
            socket.connect();
        socket.on('connect', () => {
            socket.emit('join', {room_id: room})
        })
    }, [])

    useEffect( async () => {
        if(user){
            socket.auth = {username: user.name} ;
                socket.connect();
            socket.on('connect', () => {
                socket.emit('join', {room_id: room})
            })
        }
    }, [user])

    useEffect( () => {
        socket.on('receive_chat_info', (content: any) => setChatInfo({...chatInfo, connected_users: content}))
        socket.on('receive_message', (content: any) => setMessages(prevState => [...prevState, content]))
        socket.on('receive_invitation', (content: any) => { setHost(content.host) ;  setIsOpen(!isOpen); })
        socket.on('invitation_was_accepted', (content: any) => navigate(`/pong?name=${user.name}&room_id=${content.game_room}`))
        socket.on('invitation_was_declined', (content: any) => alert('Your invitation was declined'))
        socket.on('adm-updated', (content: any) => setChatInfo({...chatInfo, adms: content}))
        socket.on('ban-updated', (content: any) => setChatInfo({...chatInfo, adms: content}))
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
    const clickOnUser = (clickedUser) => {
        if(user.name != clickedUser)
        setSelectedUser(clickedUser);setIsSelected(true)
    }
  
    const checkOwner = () => {
        if (chatInfo.owner === (user.name))
            return (<><br></br><li style={{cursor: 'pointer'}} onClick={setAdm} >Set {selectedUser} as Administrator</li></>)
        else
            return(<></>)
    }

    const setAdm = ( ) => {
        const arr: string[] = chatInfo.adms
        arr.push(selectedUser)
        socket.emit('set-adm', {target: arr, room_id: room})
    }

    const ban = () => {
        const arr: string[] = chatInfo.ban_list
        arr.push(selectedUser)
        socket.emit('ban-user', {target: arr, room_id: room})
    }

    const unBan = () => {
        const arr: string[] = chatInfo.ban_list
        for(let i = 0; i < arr.length; ++i){
            if(arr[i] === selectedUser){
                arr.splice(i, 1)
                break;
            }
        }
        socket.emit('ban-user', {target: arr, room_id: room})
    }

    const mute = () => {

    }

    const banStatus = () => {
        if(chatInfo.ban_list.includes(selectedUser))
            return(<><br></br><li style={{cursor: 'pointer'}} onClick={unBan} > Unban {selectedUser} from this room</li></>)
        return (<><br></br><li style={{cursor: 'pointer'}} onClick={ban} > Ban {selectedUser} from this room</li></>)
    }

    const checkAdm = () => {
        if (chatInfo.adms.includes(user.name))
            return (
            <>
                <br></br>
                <li style={{cursor: 'pointer'}} onClick={mute} > Mute {selectedUser} for </li>
                {banStatus()}
            </>
            
            )
        else
            return(<></>)
    }

    const displayBannedUsers = () => {
        if(chatInfo)
            return chatInfo.ban_list.map( (banned, index) => (<p key={index} style={{cursor: 'pointer'}} onClick={ () => {clickOnUser(banned)}}> {banned} </p>) )
    }

    // const displayConnectedUsers = () => {
    //     if(chatInfo) 
    //         return chatInfo.connected_list.map( (connected, index) => (<p key={index} style={{cursor: 'pointer'}} onClick={ () => {clickOnUser(connected)}}> {connected} </p>) )
    // }

    return(
        <>
        <div className='list'>
            {/* Connected Users:
            {displayConnectedUsers()}
            <br></br> */}
            Banned Users:
            {displayBannedUsers()}
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
                    {checkOwner()}
                    {checkAdm()}
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
        </div>
        </>
    )
}