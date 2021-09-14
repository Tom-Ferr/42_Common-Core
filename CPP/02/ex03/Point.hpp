/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:33:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 21:44:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(Point const & src);
	Point(float const x, float const y);
	~Point(void);
	Point & operator=(Point const & rhs);

private:
	Fixed const _x;
	Fixed const _y;

public:
	Fixed const getXcoord(void);
	Fixed const getYcoord(void);

};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif
