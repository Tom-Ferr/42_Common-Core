/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.tsx                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:19 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/20 06:48:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import Home from './components/Home/Home'
import Logged from './components/Logged';
import sketch from './pong/sketch'
import { ReactP5Wrapper } from "react-p5-wrapper";
import {BrowserRouter,Routes,Route} from "react-router-dom";
import TwoFactorAuthentication from './components/2fa/TwoFactorAuthentication';
import { Chat } from './components/chat/Chat';
import Pong from './components/Pong/Pong';

const App = () => {
    return (
        <div>
            
            <BrowserRouter>
                <Routes>
                    <Route path="/" element={<Home/>}/>
                    <Route path="/logged" element={<Logged/>}/>
                    <Route path="/pong" element={<Pong/>}/>
                    <Route path="/2fa" element={<TwoFactorAuthentication />}/>
                    <Route path="/chat" element={<Chat />}/>
                </Routes>
            </BrowserRouter>
        </div>
    )
}

export default App