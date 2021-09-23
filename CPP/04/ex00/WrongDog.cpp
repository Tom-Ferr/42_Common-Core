/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 12:22:21 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimals.hpp"

WrongDog::WrongDog(void) : WrongAnimal()
{
	std::cout << "WrongDog Default constructor has been called" << std::endl;
	this->_type = "WrongDog";
}

WrongDog::WrongDog(WrongDog const & src)
{
	std::cout << "WrongDog Copy constructor has been called" << std::endl;
	*this = src;
}

WrongDog::~WrongDog(void)
{
	std::cout << "A WrongDog has been destroyed" << std::endl;
}

WrongDog & WrongDog::operator=(WrongDog const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

void WrongDog::makeSound(void) const
{
	std::cout << "Au Au Au" << std::endl;
}
