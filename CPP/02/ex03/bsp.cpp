/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:41:09 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/24 14:11:20 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed x1, x2, x3, z;
	bool s1, s2, s3;

	Vec ab(b.getXcoord() - a.getXcoord(), b.getYcoord() - a.getYcoord());
	Vec bc(c.getXcoord() - b.getXcoord(), c.getYcoord() - b.getYcoord());
	Vec ca(a.getXcoord() - c.getXcoord(), a.getYcoord() - c.getYcoord());

	Vec ap(point.getXcoord() - a.getXcoord(), point.getYcoord() - a.getYcoord());
	Vec bp(point.getXcoord() - b.getXcoord(), point.getYcoord() - b.getYcoord());
	Vec cp(point.getXcoord() - c.getXcoord(), point.getYcoord() - c.getYcoord());

	x1 = ap.cross(ab);
	x2 = bp.cross(bc);
	x3 = cp.cross(ca);
	std::cout << "APXAB = " << x1 << std::endl;
	std::cout << "BPXBC = " << x2 << std::endl;
	std::cout << "CPXCA = " << x3 << std::endl;
	s1 = x1 > z;
	s2 = x2 > z;
	s3 = x3 > z;

	if (x1 != z && x2 != z && x3 != z)
		return (s1 == s2 && s1 == s3);
	return false ;

}
