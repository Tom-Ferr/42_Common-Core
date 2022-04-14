/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.tsx                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:28:04 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/13 19:47:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import {Canvas, useMousePressed} from 'p5-react-renderer';
import {useState, useMemo, useEffect} from 'react'
import { useSearchParams, useNavigate } from 'react-router-dom';
import io, {Socket} from 'socket.io-client'
import axios from 'axios';
const Pong = () => {

    const getSize = () => {
        return {
          width: window.innerWidth ,
          height: window.innerHeight,
        };
    };

    const [keyBlocker, setKeyBlocker] = useState(false)
    const [windowSize, setWindowSize] = useState(getSize())
    const [searchParams] = useSearchParams();
    const room = searchParams.get('room_id')
    const navigate = useNavigate()

    const [p1, setP1] = useState(undefined)
    const [p2, setP2] = useState(undefined)
    const [ball, setBall] = useState(undefined)
    const [pill, setPill] = useState(undefined)
    const [pillIsVisible, setPillIsVisible] = useState(false)
    const [user, setUser] = useState('')
    const [pause, setPause] = useState(false)
    const [slit, setSlit] = useState(false)

    const socket: Socket = useMemo( () => io('http://localhost:3000/pong', {autoConnect: false}), [])

    const loadInfo = async () => {

        await axios.get("http://localhost:3000/authentication", {withCredentials: true})
        .then(response => {
            if(response.data.name)
                setUser(response.data)
            if(response.data.gameId)
                setPause(true)
        })
        .catch(error => {
            navigate('/')
        })
    }

    useEffect( async () => {
        await loadInfo()
    }, [])

    useEffect( () => {
        if(user){
            socket.auth = {
                username: user.name,
                room_id: room
            };
            socket.connect();
            socket.on('connect', () => {
                if(user.gameId){
                    socket.emit('resume', {room_id: room})
                }

                else
                    socket.emit('join', {room_id: room, user_id: user.id})
            })
            const handleResize = () => setWindowSize(getSize());
            window.addEventListener("resize", handleResize);
            return () => window.removeEventListener("resize", handleResize);
        }
       
    }, [user])

    useEffect( () => {
        socket.on('game-refresh', (data) => {
            setBall(data.ball);
            setP1(data.p1);
            setP2(data.p2);
            setSlit(data.ball.midsIsOn)
            setPill(data.pill)
            setPillIsVisible(data.pill.isVisible)
        })
        socket.on('end-game', () => {
            navigate('/logged')
        })
        socket.on('disconnection', () => setPause(true))
        socket.on('continue', () => setPause(false))
    }, [socket])
    
    const handleKeyPress = (event) => {
        if(keyBlocker === false && (event.key === "ArrowUp" || event.key === "ArrowDown") ){
            setKeyBlocker(true)
            socket.emit('player-event', {room_id: room, isPressed: true, key: event.key})
        }
    }

    const handleKeyRelease = (event) => {
        if((event.key === "ArrowUp" || event.key === "ArrowDown") ){
            setKeyBlocker(false)
            socket.emit('player-event', {room_id: room, isPressed: false, key: event.key})
        }
    }

    const Ball = (x: number, y: number, width: number) => {

        return  <ellipse args={[x, y, width]} />

    }

    const Paddle = (x: number, y: number, width: number, height: number) => {
        
        return <rect args={[x, y, width, height]} stroke={255} />
    }

    const Line = () =>{
        return <line args={[windowSize.width / 2, 0, windowSize.width / 2, windowSize.height]} stroke={255} />
    }

    const Score = (player, pos: number) => {
        return(
            <text args={[
                player.score,
                windowSize.width * pos/100,
                windowSize.height * 7/100]}
                fill={255}
                stroke={255}
                textSize={windowSize.width * windowSize.height * 0.5/10000}
            />
        )
    }

    const PlayerName = (player_name, pos: number) => {
        return(
            <text args={[
                player_name,
                windowSize.width * pos/100,
                windowSize.height * 5/100]}
                fill={255}
                stroke={255}
                textSize={windowSize.width * windowSize.height * 0.3/10000}
            />
        )
    }

    const EndGame = () => {
        if(p1.score >= 10){
            return (<text args={[
                "Player 1 Wins",
                windowSize.width * 20/100, 
                windowSize.height * 50/100]}
                textSize = {windowSize.width * windowSize.height * 0.5/10000} 
                fill={255}
            />) 
        }  
        else{
            return( <text args={[
                "Player 2 Wins",
                windowSize.width * 60/100, 
                windowSize.height * 50/100]}
                textSize = {windowSize.width * windowSize.height * 0.5/10000} 
                fill={255} 
            />)
        }
    }

    const Main = () => {
        if(pause){
            
            useMousePressed( (event) => { 
                const clickY =  Math.round((event.pageY / windowSize.height) * 100)
                const clickX =  Math.round((event.pageX / windowSize.width) * 100)
                
                if((clickY <= 80 && clickY > 75)
                && (clickX >= 20 && clickX < 25)){
                    socket.emit('give-up', {room_id: room})
                    navigate('/logged')
                }
            })
            return(
            <>
                <text args={[
                    "Waiting for Oponnent to reconnect",
                    windowSize.width * 25/100, 
                    windowSize.height * 50/100]}
                    textSize = {windowSize.width * windowSize.height * 0.5/10000} 
                    fill={255}
                />
                <text args={[
                    "Give Up",
                    windowSize.width * 20/100, 
                    windowSize.height * 80/100]}
                    textSize = {windowSize.width * windowSize.height * 0.3/10000} 
                    fill={255}
                />

            </>)
        }
        else if(p2 == undefined){
            return (<text args={[
                "Waiting for Oponnent",
                windowSize.width * 35/100, 
                windowSize.height * 50/100]}
                textSize = {windowSize.width * windowSize.height * 0.5/10000} 
                fill={255} 
            />)
        }
        else if(p1.score < 10 && p2.score < 10){
            const midheight = windowSize.height * 30/100
            const midwidth = midheight * 10/100
            return(
                <>
                {Line()}
                {slit && Paddle((windowSize.width * 50/100) - midwidth/2, windowSize.height - midheight, midwidth,  midheight)}
                {slit && Paddle((windowSize.width * 50/100) - midwidth/2, 0, midwidth,  midheight)}
                {Ball(ball.xPosition * windowSize.width, ball.yPosition * windowSize.height, (windowSize.height * 25/100) * 15/100)}
                {pillIsVisible && Ball(pill.xPosition * windowSize.width, pill.yPosition * windowSize.height, (windowSize.height * 25/100) * 5/100)}
                {Score(p1, 40)}
                {Score(p2, 55)}
                {PlayerName(p1.name, 30)}
                {PlayerName(p2.name, 60)}
                {Paddle((p1.position * windowSize.width), p1.yPosition * windowSize.height, (windowSize.height * p1.heightProp) * 10/100, windowSize.height * p1.heightProp)}
                {Paddle((p2.position * windowSize.width), p2.yPosition * windowSize.height, (windowSize.height * p2.heightProp) * 10/100, windowSize.height * p2.heightProp)}
                </>
            )
        }
        else{

            return(
                <>
                {Line()}
                {Score(p1, 40)}
                {Score(p2, 55)}
                {PlayerName(p1.name, 30)}
                {PlayerName(p2.name, 60)}
                {EndGame()}
                </>
            )
        }
    }


    return (
        <>
        <div className="canvas"
            style={{ position: "absolute" }}
            onKeyDown={handleKeyPress}
            onKeyUp={handleKeyRelease}
            tabIndex="0">

            <Canvas size={[windowSize.width, windowSize.height]} background={0}>
                <Main />
            </Canvas>
        </div>
        </>
    )
}

export default Pong