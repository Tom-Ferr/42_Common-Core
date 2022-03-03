/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.tsx                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:19 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/02 15:21:03 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import Home from './components/Home/Home'
import Logged from './components/Logged';
import sketch from './pong/sketch'
import { ReactP5Wrapper } from "react-p5-wrapper";
import {BrowserRouter,Routes,Route} from "react-router-dom";
import TwoFactorAuthentication from './components/2fa/TwoFactorAuthentication';

const App = () => {
    return (
        <div>
            
            <BrowserRouter>
                <Routes>
                    <Route path="/" element={<Home/>}/>
                    <Route path="/logged" element={<Logged/>}/>
                    <Route path="/pong" element={<ReactP5Wrapper sketch={sketch} />}/>
                    <Route path="/2fa" element={<TwoFactorAuthentication />}/>
                </Routes>
            </BrowserRouter>
        </div>
    )
}

export default App