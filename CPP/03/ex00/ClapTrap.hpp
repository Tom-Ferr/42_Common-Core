/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 17:51:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap & operator=(ClapTrap const & rhs);

	private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		std::string const getName(void) const;
		unsigned int getHitPoint(void) const;
		unsigned int getenergyPoints(void) const;
		unsigned int getattackDamage(void) const;

		void attack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void giveName(std::string const name);

};


#endif
