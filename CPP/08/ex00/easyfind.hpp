/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:01:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/13 10:39:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T const &a, int const &b)
{
	typename T::iterator ptr = std::find(a.begin(), a.end(), b);
	if (ptr == a.end())
		throw NotFoundException();
	return (ptr);

}

#endif
