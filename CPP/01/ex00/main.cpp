/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 00:35:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 15:29:59 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie y;
	y.set_name("Gilbert");
	randomChump("Fred");
	y.announce();
	Zombie* z = newZombie("Clark");
	delete z;
	return 0;
}
