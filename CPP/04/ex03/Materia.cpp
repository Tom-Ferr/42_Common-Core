/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:46:42 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 16:00:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria(void) : _type("UNKNOWN")
{
	std::cout << "AMateria Default constructor has been called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria Default constructor has been called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria Copy constructor has been called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "A AMateria has been destroyed" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{

}
