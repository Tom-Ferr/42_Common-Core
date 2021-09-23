/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:53:30 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 10:38:22 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Pikachu");
	ClapTrap b("Meow");

	a.attack("Meow");
	b.takeDamage(a.getattackDamage());
	std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
	b.beRepaired(5);
	std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
	return 0;
}
