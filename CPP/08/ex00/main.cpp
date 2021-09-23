/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/22 12:34:44 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NotFoundException::what() const throw()
{
	return "Target not found";
}


int main( void )
{
	{
		std::vector<int> a;
		for (int i = 1; i < 10000; i++) {
			a.push_back(std::rand());
			if (i == 42)
				a.push_back(42);
		}
		try
		{
			std::vector<int>::iterator ptr = easyfind(a, 42);
			std::cout << *ptr << " found @ index: ";
			std::cout << std::distance(a.begin(), ptr) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::list<int> a;
		for (int i = 1; i < 10000; i++) {
			a.push_back(std::rand());
			if (i == 42)
				a.push_back(42);
		}
		try
		{
			std::list<int>::iterator ptr = easyfind(a, 42);
			std::cout << *ptr << " found @ index: ";
			std::cout << std::distance(a.begin(), ptr) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::deque<int> a;
		for (int i = 1; i < 10000; i++) {
			a.push_back(std::rand());
			if (i == 42)
				a.push_back(42);
		}
		try
		{
			std::deque<int>::iterator ptr = easyfind(a, 42);
			std::cout << *ptr << " found @ index: ";
			std::cout << std::distance(a.begin(), ptr) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::deque<int> a;
		for (int i = 1; i < 10000; i++) {
			a.push_back(std::rand());
			if (i == 42)
				a.push_back(424);
		}
		try
		{
			std::deque<int>::iterator ptr = easyfind(a, 42);
			std::cout << *ptr << " found @ index: ";
			std::cout << std::distance(a.begin(), ptr) << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
