/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:01:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/21 13:14:22 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char* what() const throw()
			{return "Error: Array out of range";}
	};
public:
	Array<T>(void) : _n(0), _ptr(nullptr) {return ;}
	Array<T>(unsigned int const n) : _n(n), _ptr(new T[n]()){return ;}
	Array<T>(Array const & src){*this = src;}
	~Array(void) {if(this->_ptr) delete [] this->_ptr;}
	Array & operator=(Array const & rhs)
	{
		if (this == &rhs)
			return *this;
		if(this->_ptr)
			delete [] this->_ptr;
		if (rhs.size())
		{
			this->_ptr = new T[rhs.size()];
			for (size_t i = 0; i < rhs.size(); i++) {
				this->_ptr[i] = rhs[i];
			}
		}
		else
			this->_ptr = nullptr;
		this->_n = rhs.size();
		return *this;
	}
	T & operator[](unsigned int const i) const
	{
		if (i >= this->size())
			throw OutOfRangeException();
		return this->_ptr[i];
	}

	unsigned int size(void) const {return this->_n;}

private:
	unsigned int _n;
	T* _ptr;

};
#endif
