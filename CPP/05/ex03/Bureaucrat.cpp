/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 08:57:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade = grade;
		std::cout << "Bureaucrat Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout << "Bureaucrat Copy constructor has been called" << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor has been called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::inGrade()
{
		if (this->getGrade() - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
}

void Bureaucrat::deGrade()
{
		if (this->getGrade() + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade's too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade's too high";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " cannot sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
