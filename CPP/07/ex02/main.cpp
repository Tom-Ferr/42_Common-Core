/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/21 13:16:21 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	{
		Array<std::string>a(5);
		try{
			a[6] = "8";
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		a[0] = "hello";
		Array<std::string>b(a);
		std::cout << b[0] << std::endl;
		b[0] = "bye";
		std::cout << a[0] << std::endl;
		std::cout << b[0] << std::endl;
	}
		std::cout << std::endl;
	{
		Array<int>a(5);
		try{
			a[6] = 8;
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		for (int i = 0; i < a.size(); i++) {
			std::cout << a[i] << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < a.size(); i++) {
			a[i] = i;
		}
		std::cout << std::endl;
		for (int i = 0; i < a.size(); i++) {
			std::cout << a[i] << std::endl;
		}
		std::cout << std::endl;
		a[0] = 42;
		Array<int>b = Array<int>();
		std::cout << "size of b: " << b.size() << std::endl;
		try{
			std::cout << "print b: " << b[0] << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		b = a;
		for (int i = 0; i < b.size(); i++) {
			std::cout << b[i] << std::endl;
		}
		b[0] = 21;
		std::cout << a[0] << std::endl;
		std::cout << b[0] << std::endl;
	}
}
