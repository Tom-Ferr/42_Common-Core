/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:00:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 15:39:03 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
public:

	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	std::string const & getType() const;
	void setType(std::string type);
private:
	std::string _type;

};

#endif
