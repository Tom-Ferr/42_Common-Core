import React from 'react';
import './SignIn.css';

const SignIn = () =>{
  return(
    <div className='Forms' >

      <div style={{display: 'flex' , justifyContent: 'flex-start'}}>e-mail:</div>
      <input
        name= 'e-mail'
        type='email'
      />

      <br></br>
      <br></br>

      <div style={{display: 'flex' , justifyContent: 'flex-start'}}>password:</div>
      <input
        name= 'password'
        type='password'

      />
    </div>
  )
};

export default SignIn;
