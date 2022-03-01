import React from 'react';
import './SignIn.css';
import Button from '../logginButton/logginButton';

const SignIn = () =>{

  let email: string = ""
  let password: string = ""
  let form

  const handleChange = async (event) => {
    if (event.target.name == 'e-mail')
      email = event.target.value
    else
      password = event.target.value

    form = {email, password}
  }
  
  return(
    <div className='Forms' >

      <div style={{display: 'flex' , justifyContent: 'flex-start'}}>e-mail:</div>
      <input
        name= 'e-mail'
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
      <br></br>
    <Button inputs={form} />
    </div>
  )
};

export default SignIn;
