/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:53:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/18 18:32:36 by tde-cama         ###   ########.fr       */
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
