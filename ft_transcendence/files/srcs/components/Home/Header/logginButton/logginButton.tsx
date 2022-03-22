import './logginButton.css';
import axios from 'axios';
import {useNavigate} from "react-router-dom"

const Button = (props) =>{
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

export default Button;
