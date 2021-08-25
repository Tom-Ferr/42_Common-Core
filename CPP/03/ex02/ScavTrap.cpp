/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 20:15:31 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap(void) : ClapTrap(100, 50, 20)
{
	std::cout "ScavTrap Default constructor has been called" << std::endl;
}

ScavTrap(std::string const name) : ClapTrap(100, 50, 20)
{
	this->name = name;
	std::cout << "ScavTrap" << name << "has been constructed" << std::endl;
}

ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy has been constructed" << std::endl;
	*this = src;
}

~ScavTrap(void)
{
	std::cout << "ScavTrap" << this->_name << "has been destroyed" << std::endl;
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

}

std::string ScavTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ScavTrap::getHitPoint(void) const
{
	return (this->_hitpoints);
}

unsigned int ScavTrap::getenergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int ScavTrap::getattackDamage(void) const
{
	return (this->_attack_damage);
}

void ScavTrap::attack(std::string const & target) const
{
	std::cout << "ScavTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!"
	std::cout << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if(this->_hitpoints)
	{
		std::cout << "ScavTrap " << this->_name << " was attacked " << target;
		std::cout << ", it took " << amount << " points of damage!"
		std::cout << std::endl;

		this->_hitpoints -= amount;
	}
	if(!this->_hitpoints)
	{
		std::cout << "ScavTrap " << this->_name << " is Dead!";
		std::cout << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << this->_name << " was reapaired " << target;
	std::cout << ", restoring " << amount << " of it's hit points!"
	std::cout << std::endl;

	this->_hitpoints += amount;
}

void ScavTrap::giveName(std::string const name)
{
	this->_name = name;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}
