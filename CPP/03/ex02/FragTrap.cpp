/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 21:04:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap(void) : ClapTrap(100, 100, 30)
{
	std::cout "FragTrap Default constructor has been called" << std::endl;
}

FragTrap(std::string const name) : ClapTrap(100, 100, 30)
{
	this->name = name;
	std::cout << "FragTrap" << name << "has been constructed" << std::endl;
}

FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap copy has been constructed" << std::endl;
	*this = src;
}

~FragTrap(void)
{
	std::cout << "FragTrap" << this->_name << "has been destroyed" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitpoints = rhs.getHitPoint();
		this->_energy_points = rhs.getenergyPoints();
		this->_attack_damage = rhs.getattackDamage();
	}

}

std::string FragTrap::getName(void) const
{
	return (this->_name);
}

unsigned int FragTrap::getHitPoint(void) const
{
	return (this->_hitpoints);
}

unsigned int FragTrap::getenergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int FragTrap::getattackDamage(void) const
{
	return (this->_attack_damage);
}

void FragTrap::attack(std::string const & target) const
{
	std::cout << "FragTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!"
	std::cout << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if(this->_hitpoints)
	{
		std::cout << "FragTrap " << this->_name << " was attacked " << target;
		std::cout << ", it took " << amount << " points of damage!"
		std::cout << std::endl;

		this->_hitpoints -= amount;
	}
	if(!this->_hitpoints)
	{
		std::cout << "FragTrap " << this->_name << " is Dead!";
		std::cout << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap " << this->_name << " was reapaired " << target;
	std::cout << ", restoring " << amount << " of it's hit points!"
	std::cout << std::endl;

	this->_hitpoints += amount;
}

void FragTrap::setName(std::string const name)
{
	this->_name = name;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name;
	std::cout << "  requests: High Five!" << std::endl;
}
