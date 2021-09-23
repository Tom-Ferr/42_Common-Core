/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 09:16:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", target, 5, 25)
{
	std::cout << "PresidentialPardonForm Default constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: Form("PresidentialPardonForm", src.getTaget(), 5, 25)
{
	*this = src;
	std::cout << "PresidentialPardonForm Copy constructor has been called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getStatus();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor has been called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	if (!this->getStatus())
		throw Form::IsNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();

		std::cout << executor.getName() << " executes " << this->getName() << std::endl;
		std::cout << this->getTaget() << " has been pardoned by President Redford";
		std::cout << std::endl;
}
