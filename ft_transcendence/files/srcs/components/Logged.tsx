/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logged.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/30 16:04:59 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import axios from "axios"
import io, { Socket } from 'socket.io-client'
import { useState, useEffect, useMemo } from "react";
import { useNavigate } from "react-router-dom"
import CreateChatForm from "./chat/CreateChatForm";
import ChatList from "./chat/ChatList";

const Logged = () => {
    const [user, setUser ] = useState("")
    const [activeGames, setActiveGames ] = useState([])
    const [activeChats, setActiveChats ] = useState([])
    const [loadCount, setLoadCount ] = useState(0)
    const [chatPassword, setChatPassword ] = useState("")
    const [chatOptions, setChatOptions ] = useState(false)
    const navigate = useNavigate()

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

    const socket: Socket = useMemo( () => io('http://localhost:3000/chatroom', { autoConnect: false }), [])

    const getActiveChats = async () => {

        await axios.get("http://localhost:3000/chat", {withCredentials: true})
        .then(response => {
                setActiveChats(response.data)
        })
    }

    const getActiveGames = async () => {

        await axios.get("http://localhost:3000/game", {withCredentials: true})
        .then(response => {
                setActiveGames(response.data)
        })
    }

    const displayActiveChats = () => {
        return (activeChats.map( (chats, key) => <ChatList chats={chats} id={key} join={joinChat}/> ))
    }

    useEffect( () => {
        if (loadCount == 0){
            loadInfo();
            getActiveGames();
            getActiveChats();
            setLoadCount(1)
        }
        else{
            socket.auth = {username: user.name, userID: user.id, sessionID: localStorage.getItem("sessionID")} ;
            socket.connect();
        }
    }, [user])

    useEffect( () => {
        socket.on("session", ({ sessionID, userID }) => {
            localStorage.setItem("sessionID", sessionID);
          });
        socket.on('receive_private-message', (content) => { console.log(content)})
        socket.on('update-chatlist', (content) => { console.log(content)})
        socket.on('password_checked', (content) => {
            if(content.permission)
                navigate(`/chat?name=${content.username}&room_id=${content.room_id}`)
            else
                alert('Wrong Password')
        })
    }, [socket])



    const [checked, setChecked ] = useState(user.isTwoFactorAuthenticationEnabled)

    const handleCheck = async () => {
        setChecked(!checked)
        
    }
    
    const [input, setInput] = useState("")
    const handleChange = (event) => {
        setInput(event.target.value)    
    }

    const switchTfa = async (direction: string, status: boolean) => {
        await axios.post(`http://localhost:3000/2fa/${direction}`,{twoFactorAuthenticationCode: input}, {withCredentials: true})
        .then(response => {
            setUser(values => ({...values, isTwoFactorAuthenticationEnabled: status}))
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const handleClick = async () => {
        if (user.twoFactorAuthenticationSecret)
            if(checked)
                switchTfa('turn-on', true)
            else
                switchTfa('turn-off', false)
                
        else
            await axios.get('http://localhost:3000/2fa/generate', {withCredentials: true})
    }

    const logOut = async () => {
        await axios.post('http://localhost:3000/authentication/log-out', {withCredentials: true})
        .then(response=> {
            navigate('/')
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const changeChatPassword = (event) => {
        setChatPassword(event.target.value)
    }

    const createChat = async () => {
        if(chatOptions == false){
            setChatOptions(true)
        }
        else{
            await axios.post('http://localhost:3000/chat',{owner: user.name, password: chatPassword} , {withCredentials: true})
            .then(response => {
                navigate(`/chat?name=${user.name}&room_id=${response.data.id}`)
            })
            .catch(error => {
                alert(error.message)
            })
            setChatOptions(false)

        }
    }

    const createGame = async () => {
        await axios.post('http://localhost:3000/game',{p1: user.name} , {withCredentials: true})
        .then(response => {
            navigate(`/pong?name=${user.name}&room_id=${response.data.id}`)
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const joinGame = async () => {
        let i
        for(i = activeGames.length - 1; i >= 0; --i){
            if (activeGames[i].p2 == null)
                break 
        }
        if(i < 0 ){
            createGame()
        }
        else{
            const gameID = activeGames[i].id
            await axios.put('http://localhost:3000/game',{id: gameID, p2: user.name} , {withCredentials: true})
            .then(response => {
                navigate(`/pong?name=${user.name}&room_id=${gameID}`)
            })
            .catch(error => {
                alert(error.message)
            })
        }
    }

    const joinChat =async (id, password?) => {
        socket.emit('check-chat-password', {room_id: id, password: password, username: user.name})
    }

    return (
        <>
        Hey, {user.name} Your're Logged!
        <br></br>
        <label>
            <input
                type="checkbox"
                onChange={handleCheck}
            />
            Two Factor Authentication
        </label>
        <br></br>
        <input
            type="text"
            onChange={handleChange}
        />
        <br></br>
        <input
            type="button"
            onClick={handleClick}
            value="set"
        /> 
         <br></br>
        <input
            type="button"
            onClick={logOut}
            value="logout"
        />    
         <br></br>
        
         <ul>

        {chatOptions && <CreateChatForm handleChange={changeChatPassword}/>}
        <input
            type="button"
            onClick={createChat}
            value="create Chat"
            />
        </ul>
         <br></br>

         Chat List:
         <ul>
           { displayActiveChats()}
         </ul>
           
         <br></br>
        <input
            type="button"
            onClick={joinGame}
            value="Play Game!"
        />    
         <br></br>
        <input
            type="button"
            onClick={() => navigate('/mail')}
            value="Mail"
        />    
        </>
    )
}

export default Logged