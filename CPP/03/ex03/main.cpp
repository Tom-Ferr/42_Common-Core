/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:33:24 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/18 10:57:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	{
		ClapTrap a("Pikachu");
		ClapTrap b("Meow");

		a.attack("Meow");
		b.takeDamage(a.getattackDamage());
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		b.beRepaired(5);
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		std::cout << b.getName() << "'s energy points: " << b.getenergyPoints() << std::endl;
	}
	std::cout << std::endl;
	{
		ScavTrap a("Pikachu");
		ScavTrap b("Meow");

		a.attack("Meow");
		b.takeDamage(a.getattackDamage());
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		b.beRepaired(5);
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		std::cout << b.getName() << "'s energy points: " << b.getenergyPoints() << std::endl;
		a.guardGate();
	}
	std::cout << std::endl;
	{
		FragTrap a("Pikachu");
		FragTrap b("Meow");

		a.attack("Meow");
		b.takeDamage(a.getattackDamage());
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		b.beRepaired(5);
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		std::cout << b.getName() << "'s energy points: " << b.getenergyPoints() << std::endl;
		a.highFivesGuys();
	}
	std::cout << std::endl;
	{
		DiamondTrap a("Pikachu");
		DiamondTrap b("Meow");

		a.attack("Meow");
		b.takeDamage(a.getattackDamage());
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		b.beRepaired(5);
		std::cout << b.getName() << "'s hitpoints: " << b.getHitPoint() << std::endl;
		std::cout << b.getName() << "'s energy points: " << b.getenergyPoints() << std::endl;
		a.whoAmI();
	}
	return 0;
}
