/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/09 18:51:30 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", target, 5, 25)
{
	std::cout << "PresidentialPardonForm Default constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: Form(src)
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
	static int av;

	if (!this->getStatus())
		throw Form::IsNotSignedException();
	if (executor->getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();

		std::cout << this->getTaget() << " has been pardoned by Zafod Beeblebrox";
		std::cout << std::endl;
}
