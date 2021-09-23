/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:46:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 16:29:28 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(1);
		me->equip(src->createMateria("ice"));
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character(*me);
		bob->use(0, *me);
		bob->use(1, *me);
		ICharacter* charlie = new Character(*me);
		delete me;
		bob->use(0, *charlie);
		bob->use(1, *charlie);
		delete bob;
		delete charlie;
		delete src;
	}

	return 0;
}
