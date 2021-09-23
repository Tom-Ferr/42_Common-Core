/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 19:10:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	ScavTrap(void);
public:
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & rhs);
	void guardGate(void);

	void attack(std::string const & target) const;

protected:
	unsigned int	_hitpointsMax;
	unsigned int	_energy_pointsMax;
	unsigned int	_attack_damageMax;

};

#endif
