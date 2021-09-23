/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 16:33:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP


#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	DiamondTrap(void);
public:
	DiamondTrap(std::string const name);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap(void);
	DiamondTrap & operator=(DiamondTrap const & rhs);
	void whoAmI(void) const;
	void attack(std::string const & target) const;
private:
	std::string _name;
};

#endif
