/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.tsx                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:28:04 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:28:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import {Canvas} from 'p5-react-renderer';
import {useState, useMemo, useEffect} from 'react'
import { useSearchParams, useNavigate } from 'react-router-dom';
import io, {Socket} from 'socket.io-client'
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
    const name = searchParams.get('name')
    const room = searchParams.get('room_id')
    const navigate = useNavigate()

    const [p1, setP1] = useState(undefined)
    const [p2, setP2] = useState(undefined)
    const [ball, setBall] = useState(undefined)

    const socket: Socket = useMemo( () => io('http://localhost:3000/pong', {query: {name: name}}), [])

    useEffect( () => {
        socket.on('connect', () => {
            socket.emit('join', {room_id: room})
        })
        const handleResize = () => setWindowSize(getSize());
        window.addEventListener("resize", handleResize);
        return () => window.removeEventListener("resize", handleResize);
       
    }, [])

    useEffect( () => {
        socket.on('game-refresh', (data) => {
            setBall(data.ball);
            setP1(data.p1);
            setP2(data.p2);
        })
        socket.on('end-game', () => {
            navigate('/logged')
        })
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
        if(p2 == undefined){
            return (<text args={[
                "Waiting for Oponnent",
                windowSize.width * 35/100, 
                windowSize.height * 50/100]}
                textSize = {windowSize.width * windowSize.height * 0.5/10000} 
                fill={255} 
            />)
        }
        else if(p1.score < 10 && p2.score < 10){

            return(
                <>
                {Line()}
                {Ball(ball.xPosition * windowSize.width, ball.yPosition * windowSize.height, (windowSize.height * 25/100) * 15/100)}
                {Score(p1, 40)}
                {Score(p2, 55)}
                {PlayerName(p1.name, 30)}
                {PlayerName(p2.name, 60)}
                {Paddle((p1.position * windowSize.width), p1.yPosition * windowSize.height, (windowSize.height * 25/100) * 10/100, windowSize.height * 25/100)}
                {Paddle((p2.position * windowSize.width), p2.yPosition * windowSize.height, (windowSize.height * 25/100) * 10/100, windowSize.height * 25/100)}
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