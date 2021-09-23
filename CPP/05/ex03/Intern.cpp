/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 19:34:35 by tde-cama         ###   ########.fr       */
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
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i;
	for (i = 0; i <= 3; i++) {
		if (forms[i] == name)
			break;
	}
	switch (i) {
		case 0:
			std::cout << "Intern creates " << "RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case 1:
			std::cout << "Intern creates " << "PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		case 2:
			std::cout << "Intern creates " << "ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			throw Intern::InternException();
	}
}
