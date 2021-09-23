/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:54:47 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 09:15:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

int main()
{
	{
		try
		{
			Bureaucrat a("Alice", 25);
			Bureaucrat b("Bob", 1);
			Intern  someRandomIntern;
			Form* af =  someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << *af << std::endl;
			a.signForm(*af);
			std::cout << *af << std::endl;
			a.executeForm(*af);
			b.executeForm(*af);
			delete af;
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
			Intern  someRandomIntern;
			Form* af =  someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << *af << std::endl;
			a.signForm(*af);
			std::cout << *af << std::endl;
			a.executeForm(*af);
			for (int i = 0; i < 10; i++) {
				b.executeForm(*af);
			}
			delete af;
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
			Intern  someRandomIntern;
			Form* af =  someRandomIntern.makeForm("shrubbery creation", "Bender");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << *af << std::endl;
			a.signForm(*af);
			std::cout << *af << std::endl;
			a.executeForm(*af);
			b.executeForm(*af);
			delete af;
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
			Intern  someRandomIntern;
			Form* af =  someRandomIntern.makeForm("blah", "Bender");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << *af << std::endl;
			a.signForm(*af);
			std::cout << *af << std::endl;
			a.executeForm(*af);
			b.executeForm(*af);
			delete af;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
