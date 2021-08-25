/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:33:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/17 13:41:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);
	Fixed & operator =  (Fixed const & rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int _pointPosition;
	static const int _widht;


};


#endif
