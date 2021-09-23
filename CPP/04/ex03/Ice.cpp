/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:46:42 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/18 12:12:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice Default constructor has been called" << std::endl;
}

Ice::Ice(Ice const & src)
{
	std::cout << "Ice Copy constructor has been called" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << "An Ice has been destroyed" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	return *this;
}

AMateria* 	Ice::clone(void) const
{

	AMateria* clone = new Ice();

	*clone = *this;
	return clone;
};

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}
