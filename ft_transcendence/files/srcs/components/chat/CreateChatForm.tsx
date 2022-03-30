const CreateChatForm = (props) => {
    return(

        <li>
            Protect Chat with password?
            <br></br>
            <input
            type="password"
            onChange={props.handleChange}
            />
            </li>

    )
}

export default CreateChatForm