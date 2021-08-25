/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:26:36 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 14:43:58 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(void)
{
	return ;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << weapon->getType() << std::endl;
}
