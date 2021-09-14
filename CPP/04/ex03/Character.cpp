/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:29:01 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 15:45:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("UNNAMED")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	std::cout << "Character Default constructor has been called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	std::cout << "Character Default constructor has been called" << std::endl;

}

Character::Character(Character const & src)
{
	std::cout << "Character Copy constructor has been called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "A Character has been destroyed" << std::endl;
}

Character & Character::operator=(Character const &rhs)
{
	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}

	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	this->_name = rhs.getName();

	return *this;
}

std::string const & Character::getName(void) const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	if (!m->getType().compare("ice") || !m->getType().compare("cure")){
		for (int i = 0; i < 4; i++) {
			if (!this->_inventory[i])
				this->_inventory[i] = m;
		}
	}
}

void Character::unequip(int idx)
{
	this->_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
	}

};
