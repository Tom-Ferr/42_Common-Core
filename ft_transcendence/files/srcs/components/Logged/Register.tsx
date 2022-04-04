import axios from "axios"
import { useNavigate } from "react-router-dom"
import { useState, useEffect } from 'react'

const Register = () =>{

    const [pickName, setPickName] = useState('')
    const [user, setUser] = useState('')
    const navigate = useNavigate()

    const loadInfo = async () => {

        await axios.get("http://localhost:3000/authentication", {withCredentials: true})
        .then(response => {
            if(response.data){
                setUser(response.data)
            }
        })
        .catch(error => {
            navigate('/')
        })
    }

    useEffect( () => loadInfo(),[])

    const ChangeName = async () => {
        await axios.put('http://localhost:3000/authentication/username', {...user, name: pickName}, {withCredentials: true})
        .then( response => {
            navigate('/logged')
        })
        .catch(error => {
            navigate('/')
        })
    }

    return(
        <>
            <div>
                Please, choose a nickname:
                <input type='text' value={pickName} onChange={(event) => setPickName(event.target.value)}/>
                <input type='button' value='Confirm' onClick={ChangeName}/>
            </div>
        </>
    )
}

export default Register