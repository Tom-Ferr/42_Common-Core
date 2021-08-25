/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 23:45:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap(void) : ScavTrap(), FragTrap()
{
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout "DiamondTrap Default constructor has been called" << std::endl;
}

DiamondTrap(std::string const name) : ScavTrap(), FragTrap()
{
	this->name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap" << name << "has been constructed" << std::endl;
}

DiamondTrap(DiamondTrap const & src)
{
	std::cout << "DiamondTrap copy has been constructed" << std::endl;
	*this = src;
}

~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitpoints = rhs.getHitPoint();
		this->_energy_points = rhs.getenergyPoints();
		this->_attack_damage = rhs.getattackDamage();
	}

}

std::string DiamondTrap::getName(void) const
{
	return (this->_name);
}

unsigned int DiamondTrap::getHitPoint(void) const
{
	return (this->_hitpoints);
}

unsigned int DiamondTrap::getenergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int DiamondTrap::getattackDamage(void) const
{
	return (this->_attack_damage);
}

void DiamondTrap::attack(std::string const & target) const
{
	ScavTrap::attack(target);
}

void DiamondTrap::setName(std::string const name)
{
	this->_name = name;
}
