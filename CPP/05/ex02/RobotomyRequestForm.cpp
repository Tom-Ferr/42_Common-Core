/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/09 18:55:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", target, 45, 72)
{
	std::cout << "RobotomyRequestForm Default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: Form(src)
{
	*this = src;
	std::cout << "RobotomyRequestForm Copy constructor has been called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getStatus();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor has been called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static unsigned int av;

	if (!this->getStatus())
		throw Form::IsNotSignedException();
	if (executor->getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (++av % 2){
		std::cout << "Bip...Bop...BzzzRhrh...TKnnn...Kpmmm...Psshh" << std::endl;
		std::cout << this->getTaget() << " has been robotomized successfully";
		std::cout << std::endl;
	}
	else
		std::cout << "Robotomy has failed" << std::endl;
}
