/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Points.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 20:58:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	std::cout << "Default constructor called"  << std::endl;
}

Point::Point(Point const & src)
{
	std::cout << "Copy constructor called"  << std::endl;
	*this = src;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
	std::cout << "Default constructor called"  << std::endl;
}

Point::~Point(void)
{
	std::cout << "Destructor called"  << std::endl;
	return ;
}

Point & Point::operator =  (Point const & rhs)
{
	std::cout << "Assignation operator called"  << std::endl;
	if (this != &rhs)
	{
		this->x = rhs.getXcoord();
		this->y = rhs.getYcoord();
	}
	return *this;
}

float const getXcoord(void)
{
	return this->x;
}
float const getYcoord(void)
{
	return this->y;
}
