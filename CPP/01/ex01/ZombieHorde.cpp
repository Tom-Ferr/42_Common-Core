/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:55:57 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/15 10:39:25 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* z = new Zombie[N];

	while (N)
	{
		std::string z_n = name + std::to_string(N);
		z[--N].set_name(z_n);
	}
	return &z[N];
}
