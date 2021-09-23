/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 11:10:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		ClapTrap(void);
	public:
		ClapTrap(unsigned int a, unsigned int b, unsigned int c);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap & operator=(ClapTrap const & rhs);

	protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		std::string getName(void) const;
		unsigned int getHitPoint(void) const;
		unsigned int getenergyPoints(void) const;
		unsigned int getattackDamage(void) const;

		void attack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void giveName(std::string const name);

};


#endif
