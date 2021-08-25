/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 12:34:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat Default constructor has been called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat Copy constructor has been called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "A Cat has been destroyed" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miau" << std::endl;
}
