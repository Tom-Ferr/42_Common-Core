/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateChatForm.tsx                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:26 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:27:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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