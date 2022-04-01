import {useState} from 'react'

const ChatList = (props) => {

    const [password, setPassword] = useState('')

    if(props.chats.status === 'public'){
        return (
            (<label key={props.id}>
                <li key={props.id}>{props.chats.owner}</li> 
                <input type="button" onClick={() => {props.join(props.chats.id)}} value="join"/> 
            </label>)
        )
    }
    else if(props.chats.status === 'protected'){
        return (
            (<label key={props.id}>
                <li key={props.id}>{props.chats.owner}</li>
                <input type="password" onChange={ event => setPassword(event.target.value) }/>
                <input type="button" onClick={() => {props.join(props.chats.id, password)}} value="join"/>
            </label>)
        )
    }
    
}

export default ChatList