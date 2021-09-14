/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:17:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 15:42:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	HumanA(void);
public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void attack(void);

private:
	std::string _name;
	Weapon* _weapon;
};

#endif
