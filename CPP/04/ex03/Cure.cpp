/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:46:42 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 15:47:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure Default constructor has been called" << std::endl;
}

Cure::Cure(Cure const & src)
{
	std::cout << "Cure Copy constructor has been called" << std::endl;
	*this = src;
}

Cure::~Cure(void)
{
	std::cout << "A Cure has been destroyed" << std::endl;
}

Cure & Cure::operator=(Cure const & rhs)
{
	return *this;
}

AMateria* Cure::clone(void) const
{

	AMateria* clone = new Cure;

	*clone = *this;
	return clone;
};

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "’s wounds *" << std::endl;
}
