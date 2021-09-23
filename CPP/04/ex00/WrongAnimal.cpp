/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 12:14:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimals.hpp"

WrongAnimal::WrongAnimal(void) : _type("UNKNOWN")
{
	std::cout << "WrongAnimal Default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "WrongAnimal Copy constructor has been called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "A WrongAnimal has been destroyed" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I am an WrongAnimal" << std::endl;
}
