/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:33:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/16 09:45:21 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const d);
	Fixed(float const f);
	~Fixed(void);
	Fixed & operator=(Fixed const & rhs);

private:
	int _pointPosition;
	static const int _width;

public:
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator<(Fixed const & rhs) const;
	bool operator>(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;

	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	static Fixed & min(Fixed& a, Fixed& b);
	static Fixed & max(Fixed& a, Fixed& b);
	static Fixed const & min(Fixed const &a, Fixed const &b);
	static Fixed const & max(Fixed const &a, Fixed const &b);


};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);


#endif
