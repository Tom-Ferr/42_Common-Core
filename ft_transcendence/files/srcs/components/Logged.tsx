/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logged.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/02 21:26:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import axios from "axios"
import { useState, useEffect } from 'react'
import { useNavigate } from "react-router-dom"

const Logged = () => {
    const [user, setUser ] = useState("")
    const [loadCount, setLoadCount ] = useState(0)
    const navigate = useNavigate()

    const loadInfo = () => {

        axios.get("http://localhost:3000/authentication", {withCredentials: true})
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

    const handleClick = async () => {
        if (user.twoFactorAuthenticationSecret)
            if(checked)
                await axios.post('http://localhost:3000/2fa/turn-on',{twoFactorAuthenticationCode: input}, {withCredentials: true})
                .then(response => {
                    setUser(values => ({...values, isTwoFactorAuthenticationEnabled: true}))
                })
                .catch(error => {
                    alert(error.message)
                })
            else
                await axios.post('http://localhost:3000/2fa/turn-off',{twoFactorAuthenticationCode: input}, {withCredentials: true})
                .then(response => {
                    setUser(values => ({...values, isTwoFactorAuthenticationEnabled: false}))
                })
                .catch(error => {
                    alert(error.message)
                })
                
        else
            await axios.get('http://localhost:3000/2fa/generate', {withCredentials: true})
    }


    return (
        <>
        Hey, {user.name} Your're Logged!
        <br></br>
        <label>
            <input
                type="checkbox"
                checked={checked}
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
        </>
    )
}

export default Logged