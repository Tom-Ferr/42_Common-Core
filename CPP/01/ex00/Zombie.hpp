/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 00:14:09 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 10:43:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	std::string name;
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie();
	void set_name(std::string name);
	void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
