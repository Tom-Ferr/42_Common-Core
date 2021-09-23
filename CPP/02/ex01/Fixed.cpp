/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/15 13:22:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_width = 8;

Fixed::Fixed(void) : _pointPosition(0)
{
	std::cout << "Default constructor called"  << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called"  << std::endl;
	*this = src;
}

Fixed::Fixed(int const d)
{
	std::cout << "Int constructor called"  << std::endl;
	this->_pointPosition = d << _width;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called"  << std::endl;
	this->_pointPosition = roundf(f * (1 << _width));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called"  << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called"  << std::endl;
	if (this != &rhs)
		this->_pointPosition = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called"  << std::endl;
	return this->_pointPosition;
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called"  << std::endl;
	this->_pointPosition = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)this->_pointPosition / (1 << _width);
}

int Fixed::toInt( void ) const
{
	return this->_pointPosition >> _width;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
