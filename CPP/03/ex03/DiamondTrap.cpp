/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 18:53:01 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << "DiamondTrap Default constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap()
{
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpointsMax;
	this->_energy_points = ScavTrap::_energy_pointsMax;
	this->_attack_damage = FragTrap::_attack_damageMax;
	ClapTrap::_name = this->_name + "_clap_name";
	std::cout << "DiamondTrap " << name << " has been constructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	std::cout << "DiamondTrap copy has been constructed" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
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
	return *this ;
}

void DiamondTrap::attack(std::string const & target) const
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "Hi, my name is " << this->_name;
	std::cout << " and my clapTrap name is " << ClapTrap::_name << std::endl;
}
