/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 19:10:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap(void);
public:
	FragTrap(std::string const name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);
	void highFivesGuys(void);

	void attack(std::string const & target) const;
protected:
	unsigned int	_hitpointsMax;
	unsigned int	_energy_pointsMax;
	unsigned int	_attack_damageMax;
};

#endif
