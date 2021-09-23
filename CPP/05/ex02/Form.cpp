/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 18:13:09 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, std::string target, int ex_grade, int sign_grade)
	: _name(name), _target(target), _exec_grade(ex_grade), _sign_grade (sign_grade), _signed(false)
{
	std::cout << "Form Default constructor has been called" << std::endl;

	if (ex_grade > 150 || sign_grade > 150)
		throw Form::GradeTooLowException();
	else if (ex_grade < 1 || sign_grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const & src)
: _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade()), _signed(false)
{
	*this = src;
	std::cout << "Form Copy constructor has been called" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getStatus();
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor has been called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_sign_grade;
}

int Form::getExecGrade() const
{
	return this->_exec_grade;
}

bool Form::getStatus() const
{
	return this->_signed;
}

std::string Form::getTaget() const
{
	return this->_target;
}

void Form::beSigned(Bureaucrat const & bur)
{
		if(this->getStatus())
			throw Form::IsSignedException();
		if(bur.getGrade() > this->getSignGrade())
			throw Form::GradeTooLowException();
		this->_signed = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade's too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade's too high";
}

const char* Form::IsSignedException::what() const throw()
{
	return "Form is already signed";
}

const char* Form::IsNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	std::string status = "not signed.";
	if (rhs.getStatus())
		status = "signed.";
	o << rhs.getName() << ", requires Grade " << rhs.getSignGrade() << " to be signed, and Grade ";
	o << rhs.getExecGrade() << " to be executed. It is " << status;
	return o;
}
