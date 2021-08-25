/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Points.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 19:13:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed())
{
	std::cout << "Default constructor called"  << std::endl;
}

Point::Point(Point const & src)
{
	std::cout << "Copy constructor called"  << std::endl;
	*this = src;
}

Point::Point(float const x, float const y)
{
	Fixed a.(x);
	Fixed b.(y);

	this->x = a;
	this->y = b;
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
