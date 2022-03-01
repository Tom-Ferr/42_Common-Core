import React from 'react';
import './logginButton.css';
import axios from 'axios';
import {useNavigate} from "react-router-dom"

const Button = (props) =>{
  const navigate = useNavigate()
  const handleClick = (event) => {
    event.preventDefault();
    axios.post("http://localhost:3000/authentication/log-in", props.inputs)
    .then(response => {
      if(response.data.user)
        navigate('/logged')
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

export default Button;
