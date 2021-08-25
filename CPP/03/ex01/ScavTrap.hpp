/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 17:55:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap"

class ScavTrap : public ClabTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string const name);
	ScavTrap(ClapTrap const & src);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & rhs);
	void guardGate(void);
};

#endif
