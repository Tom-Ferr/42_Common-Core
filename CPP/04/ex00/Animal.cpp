/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 12:35:40 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

Animal::Animal(void) : _type("UNKNOWN")
{
	std::cout << "Animal Default constructor has been called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal Copy constructor has been called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "A Animal has been destroyed" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "I am an Animal" << std::endl;
}
