/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:54:47 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/19 19:03:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		try
		{
			Bureaucrat a("Alice", 25);
			Bureaucrat b("Bob", 1);
			PresidentialPardonForm af("Scofield");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << af << std::endl;
			a.signForm(af);
			std::cout << af << std::endl;
			a.executeForm(af);
			b.executeForm(af);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat a("Alice", 60);
			Bureaucrat b("Bob", 1);
			RobotomyRequestForm af("Scofield");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << af << std::endl;
			a.signForm(af);
			std::cout << af << std::endl;
			a.executeForm(af);
			for (int i = 0; i < 10; i++) {
				b.executeForm(af);
			}
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat a("Alice", 145);
			Bureaucrat b("Bob", 1);
			ShrubberyCreationForm af("Scofield");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << af << std::endl;
			a.signForm(af);
			std::cout << af << std::endl;
			a.executeForm(af);
			b.executeForm(af);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
