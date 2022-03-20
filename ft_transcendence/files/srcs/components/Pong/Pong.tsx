import {Canvas} from 'p5-react-renderer';
import {useState, useMemo, useEffect} from 'react'
import io, {Socket} from 'socket.io-client'
const Pong = () => {

    const getSize = () => {
        return {
          width: window.innerWidth,
          height: window.innerHeight,
        };
    };

    const [keyBlocker, setKeyBlocker] = useState(false)
    const [windowSize, setWindowSize] = useState(getSize())

    const [p1, setP1] = useState(undefined)
    const [p2, setP2] = useState(undefined)
    const [ball, setBall] = useState(undefined)

    const socket: Socket = useMemo( () => io('http://localhost:3000'), [])

    useEffect( () => {
        socket.on('connect', () => console.log("conectado"))
        const handleResize = () => setWindowSize(getSize());
        window.addEventListener("resize", handleResize);
        return () => window.removeEventListener("resize", handleResize);
       
    }, [])

    useEffect( () => {
        socket.on('connect', () => console.log("conectado"))
        socket.on('game-refresh', (data) => {
            setBall(data.ball);
            setP1(data.p1);
            setP2(data.p2);
        })
    }, [socket])
    
    const handleKeyPress = (event) => {
        if(keyBlocker === false && (event.key === "ArrowUp" || event.key === "ArrowDown") ){
            setKeyBlocker(true)
            socket.emit('player-event', {isPressed: true, key: event.key})
        }
    }

    const handleKeyRelease = (event) => {
        if((event.key === "ArrowUp" || event.key === "ArrowDown") ){
            setKeyBlocker(false)
            socket.emit('player-event', {isPressed: false, key: event.key})
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

    const PlayerName = (player, pos: number) => {
        return(
            <text args={[
                player.name,
                windowSize.width * pos/100, //pos = 30 | 60
                windowSize.height * 5/100]}
                fill={255}
                stroke={255}
                textSize={windowSize.width * windowSize.height * 0.3/10000}
            />
        )
    }

    const Main = () => {
        if(p2 == undefined){
            console.log(p1)
            return (<text args={[
                "Waiting for Oponnent",
                windowSize.width * 35/100, 
                windowSize.height * 50/100]}
                textSize = {windowSize.width * windowSize.height * 0.5/10000} 
                fill={255} 
            />)
        }
        else{
            return(
                <>
                {Line()}
                {Ball(ball.xPosition * windowSize.width, ball.yPosition * windowSize.height, (windowSize.height * 25/100) * 15/100)}
                {Score(p1, 40)}
                {Score(p2, 55)}
                {Paddle((p1.position * windowSize.width), p1.yPosition * windowSize.height, (windowSize.height * 25/100) * 10/100, windowSize.height * 25/100)}
                {Paddle((p2.position * windowSize.width), p2.yPosition * windowSize.height, (windowSize.height * 25/100) * 10/100, windowSize.height * 25/100)}
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