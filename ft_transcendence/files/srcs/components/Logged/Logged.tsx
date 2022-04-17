/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logged.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/16 17:03:35 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import axios from "axios"
import io, { Socket } from 'socket.io-client'
import { useState, useEffect, useMemo } from "react";
import { useNavigate } from "react-router-dom"
import CreateChatForm from "../chat/CreateChatForm";
import ChatList from "../chat/ChatList";
import Popup from "../PopUp/PopUp";
import '../PopUp/popup.css'

const Logged = () => {
    const [user, setUser ] = useState("")
    const [activeChats, setActiveChats ] = useState([])
    const [activeGames, setActiveGames ] = useState([])
    const [chatPassword, setChatPassword ] = useState("")
    const [chatOptions, setChatOptions ] = useState(false)
    const [gameOptions, setGameOptions ] = useState(false)
    const [checked, setChecked ] = useState(false)
    const [input, setInput] = useState("")
    const [QRCode, setQRCode] = useState(null)
    const [showQRCode, setShowQRCode] = useState(false)
    const [slit, setSlit] = useState(false)
    const [pill, setPill] = useState(false)
    const [showCurrentGames, setShowCurrentGames] = useState(false)
    const [currentGamesButtonValue, setCurrentGamesButtonValue] = useState('show')
    const [friends, setFriends] = useState([])
    const [friendStatus, setFriendStatus] = useState([])
    const navigate = useNavigate()

    const [password, setPassword] = useState('')

    const loadInfo = async () => {

        await axios.get("http://localhost:3000/authentication", {withCredentials: true})
        .then(response => {
            if(response.data.name){
                setUser(response.data)
                setChecked(response.data.isTwoFactorAuthenticationEnabled)
                setFriends(response.data.friend_list)
            }
            else
                navigate('/register')
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
        // return (activeChats.map( (chats, key) => <ChatList chats={chats} id={key} join={joinChat}/> ))
        return (activeChats.map( (chats, key) => {

            if(chats.status === 'public'){
                return (
                    (<label key={key}>
                        <li key={key}>{chats.owner}</li> 
                        <input type="button" onClick={() => {joinChat(chats.id)}} value="join"/> 
                    </label>)
                )
            }
            else if(chats.status === 'protected'){
                return (
                    (<label key={key}>
                        <li key={key}>{chats.owner}</li>
                        <input type="password" onChange={ event => setPassword(event.target.value) }/>
                        <input type="button" onClick={() => {joinChat(chats.id, password)}} value="join"/>
                    </label>)
                )
            }
        }))
    }

    useEffect( async() => {
        await getActiveChats();
        await getActiveGames();
        loadInfo();
    }, [])

    useEffect( () => {
        if(user){
            socket.auth = {username: user.name, userID: user.id, sessionID: localStorage.getItem("sessionID")} ;
            socket.connect();
        }
    }, [user])

    useEffect( () => {
        socket.on("session", ({ sessionID, userID }) => {
            localStorage.setItem("sessionID", sessionID);
        });
        socket.on('update-chatlist', (content) => { console.log(content)})
        socket.on('friend-status-updated', (content) => { setFriendStatus(content)})
        socket.on('password_checked', (content) => {
            if(content.permission)
                navigate(`/chat?name=${content.username}&room_id=${content.room_id}`)
            else
                alert('Wrong Password')
        })
    }, [socket])


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
        if (user.twoFactorAuthenticationSecret){
            if(checked)
                switchTfa('turn-on', true)
            else
                switchTfa('turn-off', false)
        }  
        else{
            await axios.post(`http://localhost:3000/2fa/generate`, {user}, {withCredentials: true, responseType: 'blob'})
            .then(response => {
                setQRCode(response.data)
                setShowQRCode(!showQRCode)
            })
        }
    }

    const logOut = async () => {
        await axios.get('http://localhost:3000/authentication/log-out', {withCredentials: true})
        .then(response=> {
            navigate('/')
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const createChat = async () => {
        if(chatOptions == false){
            setChatOptions(true)
        }
        else{
            await axios.post('http://localhost:3000/chat',{owner: user.name, password: chatPassword, adms: [user.name]} , {withCredentials: true})
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
        await axios.post('http://localhost:3000/game',{p1: user.name, mids: slit, pill: pill} , {withCredentials: true})
        .then(response => {
            navigate(`/pong?name=${user.name}&room_id=${response.data.id}`)
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const joinGame = async () => {
        if (user.gameId){ 
            navigate(`/pong?name=${user.name}&room_id=${user.gameId}`)
            return 
        }
        const {data} = await axios.get("http://localhost:3000/game", {withCredentials: true})
        let i
        for(i = data.length - 1; i >= 0; --i){
            console.log(data[i].p2)
            if (data[i].p2 == null){}
                break 
        }
        if(i < 0 ){
            if(gameOptions == false){
                setGameOptions(true)
                return
            }
            createGame()
        }
        else{
            const gameID = data[i].id
            await axios.put('http://localhost:3000/game',{id: gameID, p2: user.name} , {withCredentials: true})
            .then(response => {
                navigate(`/pong?name=${user.name}&room_id=${gameID}`)
            })
            .catch(error => {
                alert(error.message)
            })
        }
    }

    const hideOrShow = () => {
        if (showCurrentGames)
            setCurrentGamesButtonValue('hide')
        else
            setCurrentGamesButtonValue('show')
    }

    const displayCurrentGames = () => {
        if(activeGames)
            return activeGames.map((game , index) => {
                if(game.p1 && game.p2)
                    return ( (<li key={index}><p>{game.p1} VS. {game.p2}</p> <input type='button' value='watch' onClick={() => navigate(`/pong?name=${user.name}&room_id=${game.id}`)} /> </li>) )
            })
    }

    const joinChat = async (id, password?) => {
        socket.emit('check-chat-password', {room_id: id, password: password, username: user.name})
    }

    const displayFriends = () => {
        socket.emit('get-friend-status', {friends: friends})
        if(friends && friendStatus)
            return friends.map((friends, index) => (<li key={index}>{friends} is {friendStatus[index]}</li>))

    }

    return (
        <>
        Hey, {user.name} Your're Logged!
        <br></br>
        <div>
            <input
                type="checkbox"
                checked={checked}
                onChange={() => setChecked(!checked)}
            />
            Two Factor Authentication
        </div>
        <br></br>
        <input
            type="text"
            onChange={(event) => setInput(event.target.value)}
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

        {chatOptions && <CreateChatForm handleChange={(event) => setChatPassword(event.target.value)}/>}
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
        {gameOptions &&
            <div>
                Slit?
                <input 
                    type="checkbox"
                    checked={slit}
                    onChange={() => setSlit(!slit)}
                />
                Pill?
                <input 
                    type="checkbox"
                    checked={pill}
                    onChange={() => setPill(!pill)}
                />
            </div>
        }
        <input
            type="button"
            onClick={joinGame}
            value="Play Game!"
        /> 
        <br></br>
        <div>
            Matches History:
            <br></br>
            <input type='button' value={currentGamesButtonValue} onClick={() => {setShowCurrentGames(!showCurrentGames); hideOrShow()}} />
            {showCurrentGames &&
            <div>
                {displayCurrentGames()}
            </div>
            }

        </div>   
         <br></br>
        <input
            type="button"
            onClick={() => navigate('/mail')}
            value="Mail"
        /> 
        {showQRCode && <Popup
            content={<img src={URL.createObjectURL(QRCode)} />}
            handleClose={() => setShowQRCode(!showQRCode)}
        />}
        <br></br>
        Friends:
        {displayFriends()}   
        </>
    )

    
}

export default Logged