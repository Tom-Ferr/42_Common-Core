/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:30:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 21:01:25 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap Default constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(100, 100, 30)
{
	this->_name = name;
	std::cout << "FragTrap " << name << " has been constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap copy has been constructed" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " has been destroyed" << std::endl;
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
	return *this ;
}

void FragTrap::attack(std::string const & target) const
{
	std::cout << "FragTrap " << this->_name << " attack";
	std::cout << ", causing " << this->_attack_damage << " points of damage!";
	std::cout << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name;
	std::cout << "  requests: High Five!" << std::endl;
}
