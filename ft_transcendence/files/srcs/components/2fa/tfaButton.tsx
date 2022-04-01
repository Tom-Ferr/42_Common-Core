/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfaButton.tsx                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:26:51 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:26:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import '../Home/Header/logginButton/logginButton.css';

import axios from 'axios';
import {useNavigate} from "react-router-dom"

const Button = (props) =>{
  const navigate = useNavigate()

  const handleClick = async (event) => {
    event.preventDefault();
    await axios.post("http://localhost:3000/2fa/authenticate", props.code, {withCredentials: true})
    .then(response => {
      if(response.data.name){
        if(response.data.isTwoFactorAuthenticationEnabled == true)
          navigate('/logged')
      }
    })
    .catch(error => {
     alert(error.response.data.message)
    });
  }
  return(
    <div 
      onClick={handleClick}
      className='button'>Confirm!
    </div>
  )
}

export default Button;
