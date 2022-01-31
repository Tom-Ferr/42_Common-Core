import Header from './components/Header'
import Body from './components/Body'
import sketch from './pong/sketch'
import { ReactP5Wrapper } from "react-p5-wrapper";

const App = () => {
    return (
        <div>
            {/* <Header/>
            <Body/> */}
            <ReactP5Wrapper sketch={sketch} />
        </div>
    )
}

export default App