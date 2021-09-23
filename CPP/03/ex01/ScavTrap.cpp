/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 23:40:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(100, 50, 20)
{
	std::cout << "ScavTrap Default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(100, 50, 20)
{
	this->_name = name;
	std::cout << "ScavTrap " << name << " has been constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy has been constructed" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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

void ScavTrap::attack(std::string const & target) const
{
	std::cout << "ScavTrap " << this->_name << " attack";
	std::cout << ", causing " << this->_attack_damage << " points of damage!";
	std::cout << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode." << std::endl;
}
