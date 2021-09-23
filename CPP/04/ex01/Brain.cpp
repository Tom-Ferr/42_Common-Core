/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 18:00:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::string idea = "idea_";
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = idea + std::to_string(i);
	}
	std::cout << "Brain Default constructor has been called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain Copy constructor has been called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "A Brain has been destroyed" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}
