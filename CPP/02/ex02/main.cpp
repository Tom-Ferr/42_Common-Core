/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:03:40 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 10:27:06 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		Fixed c(0.5f);
		a = b;
		if(c < a)
		std::cout << "Is lesser" << std::endl;
		a = a * c;
		std::cout << a << '\n';
	}
	std::cout << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << a.max( a, b ) << std::endl;

		Fixed c(0.5f);
		a = b;
		if(a > c)
			std::cout << "Is Greater" << std::endl;
		if(a == b)
			std::cout << "Is Equal" << std::endl;
		std::cout << b << std::endl;
		a = a * c;
		if(a != b)
			std::cout << "Is not Equal" << std::endl;
		std::cout << a << std::endl;
	}
	std::cout << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << a.min( a, b ) << std::endl;

		Fixed c(0.5f);
		a = b;
		if(a >= c)
			std::cout << "Is Greater" << std::endl;
		if(a >= b)
			std::cout << "Is Equal" << std::endl;
		std::cout << b << std::endl;
		a = a / c;
		if(a != b)
			std::cout << "Is not Equal" << std::endl;
		std::cout << a << std::endl;
	}
	std::cout << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::min( a, b ) << std::endl;

		Fixed c(0.5f);
		a = b;
		if(c <= a)
			std::cout << "Is Greater" << std::endl;
		if(a <= b)
			std::cout << "Is Equal" << std::endl;
		std::cout << b << std::endl;
		a = a / c;
		if(a != b)
			std::cout << "Is not Equal" << std::endl;
		std::cout << a << std::endl;
	}
	return 0;
}
