/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:03:40 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 11:24:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	//Point inside
	{
		Point a(10.0f, 30.0f);
		Point b(50.0f, 30.0f);
		Point c(30.0f, 60.0f);
		Point p(30.0f, 40.0f);

		std::cout << "Test1" << std::endl;
		std::cout << "Let a triangle:" << std::endl;
		std::cout << "Vertex A: " << a << std::endl;
		std::cout << "Vertex B: " << b << std::endl;
		std::cout << "Vertex C: " << c << std::endl;
		std::cout << "Is point P(" << p << ") inside of it?" << std::endl;

		if (bsp(a, b, c, p))
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;
	}
	std::cout << std::endl;
	//Point on vertex
	{
		Point a(10.0f, 30.0f);
		Point b(50.0f, 30.0f);
		Point c(30.0f, 60.0f);
		Point p(30.0f, 60.0f);

		std::cout << "Test2" << std::endl;
		std::cout << "Let a triangle:" << std::endl;
		std::cout << "Vertex A: " << a << std::endl;
		std::cout << "Vertex B: " << b << std::endl;
		std::cout << "Vertex C: " << c << std::endl;
		std::cout << "Is point P(" << p << ") inside of it?" << std::endl;

		if (bsp(a, b, c, p))
			std::cout << "Answer: True" << std::endl;
		else
			std::cout << "Answer: False" << std::endl;
	}
	std::cout << std::endl;
	//Point outside
	{
		Point a(10.0f, 30.0f);
		Point b(50.0f, 30.0f);
		Point c(30.0f, 60.0f);
		Point p(10.0f, 60.0f);

		std::cout << "Test3" << std::endl;
		std::cout << "Let a triangle:" << std::endl;
		std::cout << "Vertex A: " << a << std::endl;
		std::cout << "Vertex B: " << b << std::endl;
		std::cout << "Vertex C: " << c << std::endl;
		std::cout << "Is point P(" << p << ") inside of it?" << std::endl;

		if (bsp(a, b, c, p))
			std::cout << "Answer: True" << std::endl;
		else
			std::cout << "Answer: False" << std::endl;
	}
	std::cout << std::endl;
	//Point on edge
	{
		Point a(10.0f, 30.0f);
		Point b(50.0f, 30.0f);
		Point c(30.0f, 60.0f);
		Point p(40.0f, 45.0f);

		std::cout << "Test4" << std::endl;
		std::cout << "Let a triangle:" << std::endl;
		std::cout << "Vertex A: " << a << std::endl;
		std::cout << "Vertex B: " << b << std::endl;
		std::cout << "Vertex C: " << c << std::endl;
		std::cout << "Is point P(" << p << ") inside of it?" << std::endl;

		if (bsp(a, b, c, p))
			std::cout << "Answer: True" << std::endl;
		else
			std::cout << "Answer: False" << std::endl;
	}
}
