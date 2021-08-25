/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 18:32:41 by tde-cama         ###   ########.fr       */
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
	this->_pointPosition = d * pow(2, _width);
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called"  << std::endl;
	this->_pointPosition = roundf(f * pow(2, _width));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called"  << std::endl;
	return ;
}

Fixed & Fixed::operator =  (Fixed const & rhs)
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
	return (float)(this->_pointPosition / pow(2, _width));
}

int Fixed::toInt( void ) const
{
	return this->_pointPosition / pow(2, _width);
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
