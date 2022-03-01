/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.tsx                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:19 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/01 19:36:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import Home from './components/Home/Home'
import Logged from './components/Logged';
import sketch from './pong/sketch'
import { ReactP5Wrapper } from "react-p5-wrapper";
import {BrowserRouter,Routes,Route} from "react-router-dom";

const App = () => {
    return (
        <div>
            {/* <ReactP5Wrapper sketch={sketch} /> */}
            <BrowserRouter>
                <Routes>
                    <Route path="/" element={<Home/>}/>
                    <Route path="/logged" element={<Logged/>}/>
                    <Route path="/logged" element={<Logged/>}/>
                </Routes>
            </BrowserRouter>
        </div>
    )
}

export default App