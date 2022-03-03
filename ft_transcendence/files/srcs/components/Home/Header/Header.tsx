/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/02 09:13:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import Button from "./logginButton/logginButton"
import SignIn from "./SignIn/SignIn"
import {useState} from 'react'

const Header = () => {
    const [inputs, setInputs] = useState(
        {
            email: "",
            password: ""
        }
    )
    return (
        <>
        <nav className='signin'>
            <SignIn setInputs={setInputs}/>
            <Button inputs={inputs}/>
        </nav>
        <h1>Transcendence</h1>
        </>
    )
}

export default Header