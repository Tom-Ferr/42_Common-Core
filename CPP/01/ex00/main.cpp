/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 00:35:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 10:46:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie y;
	randomChump("Fred");
	y.set_name("Gilbert");
	y.announce();
	Zombie* z = new Zombie("Clark");
	delete z;
	return 0;
}
