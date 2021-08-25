/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 21:53:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP


#include "ScavTrap"
#include "FragTrap"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(std::string const name);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap(void);
	DiamondTrap & operator=(DiamondTrap const & rhs);
	void highFivesGuys(void);
private:
	std::string _name;
};

#endif
