/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 20:20:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat Default constructor has been called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src) : AAnimal(), _brain(nullptr)
{
	std::cout << "Cat Copy constructor has been called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "A Cat has been destroyed" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
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

void Cat::makeSound(void) const
{
	std::cout << "Miau" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return this->_brain;
}

std::string Cat::mindReader(void) const
{
	return this->_brain->_ideas[std::rand() % 100];
}
