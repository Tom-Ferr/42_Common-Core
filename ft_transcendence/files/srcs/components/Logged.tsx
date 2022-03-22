/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logged.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/22 19:34:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import axios from "axios"
import { useState, useEffect } from 'react'
import { useNavigate } from "react-router-dom"

const Logged = () => {
    const [user, setUser ] = useState("")
    const [activeGames, setActiveGames ] = useState([])
    const [activeChats, setActiveChats ] = useState([])
    const [loadCount, setLoadCount ] = useState(0)
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
        setLoadCount(1)
    }

    const getActiveChats = async () => {

        await axios.get("http://localhost:3000/chat", {withCredentials: true})
        .then(response => {
                setActiveChats(response.data)
        })
        setLoadCount(1)
    }

    const getActiveGames = async () => {

        await axios.get("http://localhost:3000/game", {withCredentials: true})
        .then(response => {
                setActiveGames(response.data)
        })
        setLoadCount(1)
    }

    const displayActiveChats = () => {
        return (activeChats.map( (chats, key) => (<label key={key}><li key={key}>{chats.owner}</li> <input type="button" onClick={() => {joinChat(chats.id)}} value="join"/> </label>) ))
    }

    useEffect(() => {
        if (loadCount == 0) { loadInfo(); getActiveGames(); getActiveChats() }
    }, [])


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

    const createChat = async () => {
        await axios.post('http://localhost:3000/chat',{owner: user.name} , {withCredentials: true})
        .then(response => {
            navigate(`/chat?name=${user.name}&room_id=${response.data.id}`)
        })
        .catch(error => {
            alert(error.message)
        })
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
        console.log(activeGames.length)
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

    const joinChat =async (id) => {
        navigate(`/chat?name=${user.name}&room_id=${id}`)
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
        <input
            type="button"
            onClick={createChat}
            value="create Chat"
        />
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
        </>
    )
}

export default Logged