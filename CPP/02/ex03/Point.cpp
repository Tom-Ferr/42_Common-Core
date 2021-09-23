/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 11:00:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point::Point(Point const & src) : _x(src.getXcoord()), _y(src.getYcoord())
{
	return ;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point & Point::operator=(Point const & rhs)
{
	return *this;
}

Fixed const Point::getXcoord(void) const
{
	return this->_x;
}

Fixed const Point::getYcoord(void) const
{
	return this->_y;
}

Fixed Point::cross(Point const & rhs) const
{
	return ((this->getXcoord() * rhs.getYcoord()) - (rhs.getXcoord() * this->getYcoord()));
}

std::ostream & operator<<(std::ostream & o, Point const & rhs)
{
	o << rhs.getXcoord() << ";" << rhs.getYcoord();
	return o;
}
