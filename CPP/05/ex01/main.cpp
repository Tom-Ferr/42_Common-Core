/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:54:47 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/20 10:19:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	try
	{
		Bureaucrat a("Alice", 150);
		Form af("Alef", 80, 50);
		std::cout << a << std::endl;
		std::cout << af << std::endl;
		a.signForm(af);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("Bob", 50);
		Form bf("Beth", 80, 50);
		std::cout << b << std::endl;
		b.signForm(bf);
		std::cout << bf << std::endl;
		b.signForm(bf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
