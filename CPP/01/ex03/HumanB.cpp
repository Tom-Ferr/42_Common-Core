/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:26:36 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 12:40:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::HumanB(void)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his ";
	std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
