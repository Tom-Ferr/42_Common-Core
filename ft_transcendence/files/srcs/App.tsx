/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.tsx                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:19 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/30 16:04:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import Home from './components/Home/Home'
import Logged from './components/Logged';
import {BrowserRouter,Routes,Route} from "react-router-dom";
import TwoFactorAuthentication from './components/2fa/TwoFactorAuthentication';
import { ChatRoom } from './components/chat/ChatRoom';
import Mail from './components/chat/mail/Mail';
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
                    <Route path="/chat" element={<ChatRoom />}/>
                    <Route path="/mail" element={<Mail />}/>
                </Routes>
            </BrowserRouter>
        </div>
    )
}

export default App