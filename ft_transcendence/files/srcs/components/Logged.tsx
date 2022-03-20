/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logged.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/18 09:20:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import axios from "axios"
import { useState, useEffect } from 'react'
import { useNavigate } from "react-router-dom"

const Logged = () => {
    const [user, setUser ] = useState("")
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

    useEffect(() => {
        if (loadCount == 0) { loadInfo() }
    })


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

    const createGame = async () => {
        await axios.post('http://localhost:3000/game',{p1: user.name} , {withCredentials: true})
        .then(response => {
            navigate('/pong')
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const joinGame = async () => {
        await axios.put('http://localhost:3000/game',{id: 20, p2: user.name} , {withCredentials: true})
        .then(response => {
            navigate('/pong')
        })
        .catch(error => {
            alert(error.message)
        })
    }

    const joinChat =async () => {
        navigate(`/chat?name=${user.name}`)
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
            onClick={createGame}
            value="create Game"
        />
         <br></br>
        <input
            type="button"
            onClick={joinGame}
            value="join"
        />    
         <br></br>
        <input
            type="button"
            onClick={joinChat}
            value="chat"
        />    
        </>
    )
}

export default Logged