/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 20:21:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

AAnimal::AAnimal(void) : _type("UNKNOWN")
{
	std::cout << "AAnimal Default constructor has been called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "AAnimal Copy constructor has been called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "A AAnimal has been destroyed" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
