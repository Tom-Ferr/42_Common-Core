/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 20:11:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap(void) : _hitpoints(10), _energy_points(10), _attack_damage(0)
{
	std::cout "Default constructor has been called" << std::endl;
}

ClapTrap(unsigned int a, unsigned int b, unsigned int c) : _hitpoints(a), _energy_points(b), _attack_damage(c)
{
	std::cout "Default constructor has been called" << std::endl;
}

ClapTrap(std::string const name) : _hitpoints(10), _energy_points(10), _attack_damage(0)
{
	this->_name = name;
	std::cout << name << "has been constructed" << std::endl;
}

ClapTrap(ClapTrap const & src)
{
	*this = src;
}

~ClapTrap(void)
{
	std::cout << this->_name << "has been destroyed" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitpoints = rhs.getHitPoint();
		this->_energy_points = rhs.getenergyPoints();
		this->_attack_damage = rhs.getattackDamage();
	}

}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoint(void) const
{
	return (this->_hitpoints);
}

unsigned int ClapTrap::getenergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::getattackDamage(void) const
{
	return (this->_attack_damage);
}

void ClapTrap::attack(std::string const & target) const
{
	std::cout << "ClapTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!"
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitpoints)
	{
		std::cout << "ClapTrap " << this->_name << " was attacked " << target;
		std::cout << ", it took " << amount << " points of damage!"
		std::cout << std::endl;

		this->_hitpoints -= amount;
	}
	if(!this->_hitpoints)
	{
		std::cout << "ClapTrap " << this->_name << " is Dead!";
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " was reapaired " << target;
	std::cout << ", restoring " << amount << " of it's hit points!"
	std::cout << std::endl;

	this->_hitpoints += amount;
}

void ClapTrap::giveName(std::string const name)
{
	this->_name = name;
}
