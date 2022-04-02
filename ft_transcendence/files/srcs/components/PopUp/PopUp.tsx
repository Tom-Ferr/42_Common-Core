/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PopUp.tsx                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:28:16 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:47:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const Popup = props => {
  return (
    <div className="popup-box">
      <div className="box">
        <span className="close-icon" onClick={props.handleClose}>x</span>
        {props.content}
      </div>
    </div>
  );
};
 
export default Popup;