/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:08:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 14:39:09 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const & Weapon::getType()
{
	return(this->type);
}
void Weapon::setType(std::string type)
{
	this->type = type;
	return ;
}
