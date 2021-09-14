/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:41:09 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/03 21:42:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed den = (b.getYcoord() - c.getYcoord())*(a.getXcoord() - c.getXcoord());
	den = den + (c.getXcoord() - b.getXcoord())*(a.getYcoord() - c.getYcoord());
	Fixed i = (b.getYcoord() - c.getYcoord())*(point.getXcoord() - c.getXcoord());
	i = i + (c.getXcoord() - b.getXcoord())*(point.getYcoord() - c.getYcoord()) / den;
	Fixed j = (c.getYcoord() - a.getYcoord())*(point.getXcoord() - c.getXcoord());
	j = j + (a.getXcoord() - c.getXcoord())*(point.getYcoord() - c.getYcoord()) / den;
	Fixed k = 1 - i - j;

	return ((0 <= i && i <= 1) && (0 <= j && j <= 1) && (0 <= k && k <= 1));
}
