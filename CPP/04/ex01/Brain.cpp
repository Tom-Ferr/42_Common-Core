/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 14:39:04 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default constructor has been called" << std::endl;
	this->_ideas = new std::string[100];
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain Copy constructor has been called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "A Brain has been destroyed" << std::endl;
	delete [] this->_ideas;
}

Brain & Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		this->_ideas = rhs._ideas;
	}
	return *this;
}
