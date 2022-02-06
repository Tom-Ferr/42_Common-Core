/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.tsx                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:19 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/31 13:09:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import Header from './components/Header/Header'
import Body from './components/Body/Body'
import sketch from './pong/sketch'
import { ReactP5Wrapper } from "react-p5-wrapper";

const App = () => {
    return (
        <div>
            <Header/>
            <Body/>
            {/* <ReactP5Wrapper sketch={sketch} /> */}
        </div>
    )
}

export default App