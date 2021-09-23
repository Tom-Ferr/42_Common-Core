/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 18:06:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default constructor has been called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src) : Animal(), _brain(nullptr)
{
	std::cout << "Dog Copy constructor has been called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "A Dog has been destroyed" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if(this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*(this->_brain) = *(rhs.getBrain());

	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Au Au Au" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return this->_brain;
}

std::string Dog::mindReader(void) const
{
	return this->_brain->_ideas[std::rand() % 100];
}
