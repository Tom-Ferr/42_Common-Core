/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/10 00:54:45 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default constructor has been called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	std::cout << "Intern Copy constructor has been called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor has been called" << std::endl;
}

const char* Intern::InternException::what() const throw()
{
	return "Intern could not create Form";
}

Form* Intern::makeForm(std::string const & name, std::string const & target)
{
	Form* arr[3];
	arr[0] = new RobotomyRequestForm(target);
	arr[1] = new PresidentialPardonForm(target);
	arr[2] = new ShrubberyCreationForm(target);

	for (int i = 0; i < 3; i++) {
		if (arr[i]->getName() == target){
			std::cout << "Intern creates " << arr[i]->getName() << std::endl;
			delete arr[i + 1 % 3];
			delete arr[i + 2 % 3];
			return arr[i];
		}
	}
	throw Intern::InternException();
}
