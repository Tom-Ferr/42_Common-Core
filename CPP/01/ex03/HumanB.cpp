/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:26:36 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 14:35:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB(void)
{
	return ;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with his " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
