/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.tsx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:41:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/31 12:57:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import SignIn from "./SignIn/SignIn"
const Header = () => {
    return (
        <>
        <nav className='signin'>
            <SignIn/>
        </nav>
        <h1>Transcendence</h1>
        </>
    )
}

export default Header