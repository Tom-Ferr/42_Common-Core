/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:17:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 15:41:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	HumanB(void);
public:

	HumanB(std::string name);
	~HumanB(void);

	void attack(void);
	void setWeapon(Weapon& weapon);

private:
	std::string _name;
	Weapon* _weapon;

};

#endif
