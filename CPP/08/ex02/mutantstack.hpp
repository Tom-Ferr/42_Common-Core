/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:01:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/22 13:28:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	MutantStack(void){};
	MutantStack(MutantStack const & src){*this = src;}
	~MutantStack(void){};
	MutantStack<T> & operator=(MutantStack<T> const & rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void){return this->c.begin();}
	iterator end(void){return this->c.end();}

};
#endif
