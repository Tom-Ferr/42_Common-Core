/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:29:01 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 15:17:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	std::cout << "MateriaSource Default constructor has been called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource Copy constructor has been called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "A MateriaSource has been destroyed" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}

	for (int i = 0; i < 4; i++) {
		if( rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}

	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] && !this->_inventory[i]->getType().compare(type))
			return this->_inventory[i]->clone();
	}
	return (0);
}
