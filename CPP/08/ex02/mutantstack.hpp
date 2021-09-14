/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:01:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/13 13:17:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	MutantStack(void){};
	MutantStack(MutantStack const & src){*this = src;}
	~MutantStack(void){};
	MutantStack & operator=(MutantStack const & rhs)
	{
		if (this != &rhs)
		 	this->_l = rhs.getLst();
		return *this;
	}
	std::list<T> getLst(void){return this->_l;}

	T top(void){return this->_l.back();}
	bool empty(void){if (!this->_l.size()) return true; return false;}
	unsigned int size(void){return this->_l.size();}
	void push(T n){this->_l.push_front(n);}
	void pop(void){this->_l.pop_front();}

	typedef typename std::list<T>::iterator iterator;

	iterator begin(void){return this->_l.begin();}
	iterator end(void){return this->_l.end();}
	iterator rbegin(void){return this->_l.rbegin();}
	iterator rend(void){return this->_l.rend();}

private:
	std::list<T> _l;

};
#endif
