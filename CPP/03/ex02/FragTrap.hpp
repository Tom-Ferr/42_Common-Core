/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 19:41:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap"

class FragTrap : public ClabTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const name);
	FragTrap(ClapTrap const & src);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);
	void highFivesGuys(void);
};

#endif
