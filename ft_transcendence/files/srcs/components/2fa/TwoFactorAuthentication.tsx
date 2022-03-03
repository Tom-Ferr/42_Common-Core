/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TwoFactorAuthentication.tsx                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:55:05 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/02 15:59:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { useState } from 'react'
import Button from './tfaButton';

const TwoFactorAuthentication = () => {
    
    const [ code, setCode ] = useState("")
    const handleChange = async (event) => {
    
        setCode({twoFactorAuthenticationCode: event.target.value})
    }
      
      return(
        <div className='Forms' >
    
          <div style={{display: 'flex' , justifyContent: 'flex-start'}}>Please, enter your code to proceed:</div>
          <input
            name= '2fa'
            type='text'
            onChange={handleChange}
          />
          <br></br>
          <Button code={code}/>
        </div>
      )
};

export default TwoFactorAuthentication