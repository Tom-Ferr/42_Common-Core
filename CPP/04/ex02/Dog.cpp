/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 20:27:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

Dog::Dog(void) : AAnimal()
{
	std::cout << "Dog Default constructor has been called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog Copy constructor has been called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "A Dog has been destroyed" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

void Dog::makeSound(void)
{
	std::cout << "Au Au Au" << std::endl;
}
