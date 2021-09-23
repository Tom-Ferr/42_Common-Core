/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/22 14:26:58 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main( void )
{
	{
		std::cout << "short example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "10.000 example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		Span sp = Span(10000);
		std::srand(time(NULL));
		int i = 0;
		while (i < sp.getMax()){
			sp.addNumber(std::rand());
			i++;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "10.000 w/ iterator example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		for (Span::iterator ptr = sp.begin(); ptr != sp.end(); ptr++) {
			*ptr = std::rand();
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "20.000 example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		Span sp = Span(20000);
		std::srand(time(NULL));
		int i = 0;
		while (i < sp.getMax()){
			sp.addNumber(std::rand());
			i++;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "20.000 w/ iterator example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		for (Span::iterator ptr = sp.begin(); ptr != sp.end(); ptr++) {
			*ptr = std::rand();
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "error: 1 element example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		Span sp = Span(1);
		std::srand(time(NULL));
		int i = 0;
		while (i < sp.getMax()){
			sp.addNumber(std::rand());
			i++;
		}
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "error: " << e.what() << std::endl;
		}
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "error: " << e.what() << std::endl;
		}
		std::cout << "-------------------------" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "error: out limits example:" << std::endl;
		std::cout << "-------------------------" << std::endl;
		Span sp = Span(5);
		std::srand(time(NULL));
		for (int i; i <= sp.getMax(); i++) {
			try
			{
				sp.addNumber(std::rand());
			}
			catch (std::exception & e)
			{
				std::cout << "error: " << e.what() << std::endl;
			}
		}
		std::cout << "-------------------------" << std::endl;
	}
}
