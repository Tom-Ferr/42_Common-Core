/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 09:17:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", target, 137, 145)
{
	std::cout << "ShrubberyCreationForm Default constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: Form("ShrubberyCreationForm", src.getTaget(), 137, 145)
{
	*this = src;
	std::cout << "ShrubberyCreationForm Copy constructor has been called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getStatus();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor has been called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
		if (!this->getStatus())
			throw Form::IsNotSignedException();
		if (executor.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException();
		std::cout << executor.getName() << " executes " << this->getName() << std::endl;
		std::string fname = this->getTaget();
		std::ofstream	ofs(fname.insert(fname.size(), "_shrubbery"));

		ofs << std::endl;
		ofs << "               ,@@@@@@@," << std::endl;
		ofs << "      ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		ofs << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		ofs << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		ofs << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		ofs << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		ofs << "  `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		ofs << "      |o|        | |         | |" << std::endl;
		ofs << "      |.|        | |         | |" << std::endl;
		ofs << "jgs\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	ofs.close();
}
