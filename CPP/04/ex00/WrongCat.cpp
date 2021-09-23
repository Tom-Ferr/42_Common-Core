/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 12:21:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimals.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat Default constructor has been called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat Copy constructor has been called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "A WrongCat has been destroyed" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miau" << std::endl;
}
