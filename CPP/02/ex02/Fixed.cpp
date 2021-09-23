/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 09:45:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_width = 8;

Fixed::Fixed(void) : _pointPosition(0)
{
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::Fixed(int const d)
{
	this->_pointPosition = d << _width;
}

Fixed::Fixed(float const f)
{
	this->_pointPosition = roundf(f * (1 << _width));
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_pointPosition = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_pointPosition;
}
void Fixed::setRawBits( int const raw )
{
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

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->_pointPosition < rhs.getRawBits());
}
bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->_pointPosition > rhs.getRawBits());
}
bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toInt() <= rhs.toInt());
}
bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toInt() >= rhs.toInt());
}
bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->toInt() == rhs.toInt());
}
bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toInt() != rhs.toInt());
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	return this->toFloat() + rhs.toFloat();
}
Fixed Fixed::operator-(Fixed const & rhs) const
{
	return this->toFloat() - rhs.toFloat();
}
Fixed Fixed::operator*(Fixed const & rhs) const
{
	return this->toFloat() * rhs.toFloat();
}
Fixed Fixed::operator/(Fixed const & rhs) const
{
	return this->toFloat() / rhs.toFloat();
}

Fixed Fixed::operator++()
{
	this->_pointPosition += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_pointPosition += 1;
	return tmp;
}

Fixed Fixed::operator--()
{
	this->_pointPosition -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_pointPosition -= 1;
	return tmp;
}

Fixed & Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}
Fixed const & Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed & Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}
