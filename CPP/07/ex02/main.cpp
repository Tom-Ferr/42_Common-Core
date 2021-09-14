/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/11 17:10:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	Array<std::string>a(5);
	// try{
	// 	a[6] = 8;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << e.what() << '\n';
	// }
	a[0] = "hello";
	Array<std::string>b(a);
	std::cout << b[0] << '\n';
	b[0] = "bye";
	std::cout << a[0] << '\n';
	std::cout << b[0] << '\n';
}
