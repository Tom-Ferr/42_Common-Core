/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/11 15:01:44 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	{
		int arr[5] = {1, 3, 5, 7, 9};
		std::cout << "before: arr[] = {";
		for (size_t i = 0; i < 5; i++) {
			if (i)
			std::cout << ", ";
			std::cout << arr[i];
		}
		std::cout << "}" << std::endl;
		iter(arr, 5, &twice);
		std::cout << "after: arr[] = {";
		for (size_t i = 0; i < 5; i++) {
			if (i)
				std::cout << ", ";
				std::cout << arr[i];
			}
			std::cout << "}" << std::endl;
	}
	std::cout << std::endl;
	{
		float arr[5] = {1.6f, 3.6f, 5.6f, 7.6f, 9.6f};
		std::cout << "before: arr[] = {";
		for (size_t i = 0; i < 5; i++) {
			if (i)
				std::cout << ", ";
			std::cout << arr[i];
		}
		std::cout << "}" << std::endl;
		iter(arr, 5, &twice);
		std::cout << "after: arr[] = {";
		for (size_t i = 0; i < 5; i++) {
			if (i)
				std::cout << ", ";
			std::cout << arr[i];
		}
		std::cout << "}" << std::endl;
	}
}
