/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:46 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/05 11:17:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import './logginButton.css';
import axios from 'axios';
import {useNavigate} from "react-router-dom"

const Tester = (props) =>{
  const navigate = useNavigate()
  const handleClick = async (event) => {
    event.preventDefault();
    await axios.post("http://localhost:3000/authentication/log-in", props.inputs, {withCredentials: true})
    .then(response => {
      if(response.data.name)
        navigate(`/logged?name=${response.data.name}`)
      else
        navigate('/2fa')
    })
    .catch(error => {
     alert(error.response.data.message)
    });
  }
  return(
    <div 
      onClick={handleClick}
      className='button'>Go!
    </div>
  )
}

export default Tester;