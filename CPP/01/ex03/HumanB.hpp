/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:17:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 14:38:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB{

	std::string name;
	Weapon* weapon;

public:

	HumanB(std::string name);
	~HumanB(void);

	void attack(void);
	void setWeapon(Weapon& weapon);

};

#endif
