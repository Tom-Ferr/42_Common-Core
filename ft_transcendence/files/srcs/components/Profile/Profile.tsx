/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Profile.tsx                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:28:21 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:48:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { useState, useEffect, useMemo, useLocation } from "react";
import { useSearchParams, useNavigate } from 'react-router-dom';
import io, { Socket } from 'socket.io-client'
import axios from "axios";
import Popup from "../PopUp/PopUp";
import '../PopUp/popup.css'

const Profile = () => {
    const [searchParams] = useSearchParams();
    const navigate = useNavigate()
    const name = searchParams.get('name')
    const [user, setUser ] = useState("")
    const [profile, setProfile ] = useState("")
    const [show, setShow ] = useState(false)
    const [historyButtonValue, setHistoryButtonValue ] = useState('show')
    const [avatar, setAvatar ] = useState(null)
    const [selectedFile, setSelectedFile ] = useState("")
    const [isOpen, setIsOpen] = useState(false);

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

    const getDefaultAvatar = async () => {

        await axios.get(`http://localhost:3000/avatar/${user.id}`, {withCredentials: true, responseType: 'blob'})
        .then(response => {
            setAvatar(response.data)
        })
        .catch(error => {
            alert('fail')
        })
    }

    const socket: Socket = useMemo( () => io('http://localhost:3000/chatroom', { autoConnect: false }), [])

    useEffect( async() => loadInfo(), [])

    useEffect( () => {
        if(user){
            socket.auth = {username: user.name, userID: user.id, sessionID: localStorage.getItem("sessionID")} ;
            socket.connect();
            getDefaultAvatar()
            let target = name
            if(!target)
                target = user.name
            socket.emit('get-profile-data', target)
        }
    }, [user])

    useEffect( () => {
        socket.on("session", ({ sessionID, userID }) => {
            localStorage.setItem("sessionID", sessionID);
          });
        socket.on('recv-profile-data', (data) => {
            if(!data.name)
                alert('user not found')
            else
                setProfile(data)
        })
            
    }, [socket])

    const ShowStats = () =>{
        if(profile)
            return <>Wins: {profile.stats.wins}, Losses: {profile.stats.losses}, Draws: {profile.stats.draws}</>
        return <></>
    }

    const ShowHistory = () =>{
        if(profile)
            return profile.matches.map((match , index) => (<li><p>{match.p1} VS. {match.p2}</p> <br></br> <p>{match.p1Score} x {match.p2Score}</p></li>))
        return <></>
    }

    const hideOrShow = () => {
        if (show)
            setHistoryButtonValue('hide')
        else
            setHistoryButtonValue('show')
    }

    const Avatar = () => {
        if(avatar){
            if(user.name == name)
                return <img style={{cursor: 'pointer'}} onClick={() => {if(user.name == name)setIsOpen(!isOpen)}} src={URL.createObjectURL(avatar)} />
            return  <img src={URL.createObjectURL(avatar)} />
        }
        return <></>
    }

    const uploadAvatar = () => {
        const formData = new FormData();
        formData.append("myFile",selectedFile, selectedFile.name);
        axios.put(`http://localhost:3000/avatar/${user.id}`, formData, {withCredentials: true})
        .then( () =>{
           setAvatar(selectedFile)
           setIsOpen(!isOpen)
        })
    }

    return(
        <>
        <h1>{profile.name}</h1>
        <h3>lvl: {profile.level}</h3>
        <div>
            Stats: 
            <br></br>
            <div>
                <ShowStats/>
            </div>
        </div>
        <div>
            Matches History:
            <br></br>
            <input type='button' value={historyButtonValue} onClick={() => {setShow(!show); hideOrShow()}} />
            {show &&
            <div>
                <ShowHistory/>
            </div>
            }

        </div>
        <div className={'avatar'} >
            <Avatar/>
        </div>
        {isOpen && <Popup
            content={<>
                Please, select a file
                <input type='file' onChange={(event) => setSelectedFile(event.target.files[0])}/>
                <input type='button' value={'Upload'} onClick={uploadAvatar}/>
            </>}
            handleClose={() => setIsOpen(!isOpen)}
        />}
        </>
    );
}

export default  Profile