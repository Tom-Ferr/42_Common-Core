/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:01:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/22 11:59:38 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &a, int  b)
{
	typename T::iterator ptr = std::find(a.begin(), a.end(), b);
	if (ptr == a.end())
		throw NotFoundException();
	return ptr;

}

#endif
