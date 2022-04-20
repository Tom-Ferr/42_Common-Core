/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logginButton.tsx                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:46 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/04 13:40:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import './logginButton.css';
import axios from 'axios';
import {useNavigate} from "react-router-dom"

const Button = (props) =>{
  const navigate = useNavigate()
  const handleClick = async (event) => {
    event.preventDefault();
    await axios.get("http://localhost:3000/oauth/login")
    .then(response => window.location.replace(response.data))
    .catch(error => {
     alert(error.response.data.message)
    });
  }
  return(
    <div 
      onClick={handleClick}
      className='button'>LogIn!
    </div>
  )
}

export default Button;
