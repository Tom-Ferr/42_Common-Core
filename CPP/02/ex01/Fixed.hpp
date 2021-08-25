/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:33:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/17 14:16:46 by tde-cama         ###   ########.fr       */
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

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
	
private:
	int _pointPosition;
	static const int _width;

};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);

#endif
