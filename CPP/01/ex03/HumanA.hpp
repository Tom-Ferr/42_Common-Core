/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:17:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 14:43:35 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{

	std::string name;
	Weapon* weapon;

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void attack(void);

};

#endif
