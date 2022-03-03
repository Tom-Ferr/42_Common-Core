/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignIn.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:52:51 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/02 14:52:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import './SignIn.css';

const SignIn = ({setInputs}) =>{

  const handleChange = async (event) => {
    const name = event.target.name
    const value = event.target.value

    setInputs(values => ({...values, [name]: value}))
  }
  
  return(
    <div className='Forms' >

      <div style={{display: 'flex' , justifyContent: 'flex-start'}}>e-mail:</div>
      <input
        name= 'email'
        type='email'
        onChange={handleChange}
      />

      <br></br>
      <br></br>

      <div style={{display: 'flex' , justifyContent: 'flex-start'}}>password:</div>
      <input
        name= 'password'
        type='password'
        onChange={handleChange}

      />
    </div>
  )
};

export default SignIn;
