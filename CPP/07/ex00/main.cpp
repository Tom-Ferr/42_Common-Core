/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/21 11:58:18 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	{
		int a = 2;
		int b = 3;
		std::cout << "before swap: " << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after swap: " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "before swap: " << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "after swap: " << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
		std::cout << std::endl;
	{
		long a = 25;
		long b = 33;
		std::cout << "before swap: " << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after swap: " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "block2a";
		std::string d = "block2b";
		std::cout << "before swap: " << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "after swap: " << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}
