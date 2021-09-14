/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:54:34 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/13 11:29:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void)
{
	return ;
}

Span::Span(unsigned int const N) : _n(N)
{
	return ;
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span(void)
{
	return ;
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs.getMax();
		this->_l = rhs.getLst();
	}
	return *this;
}

unsigned int Span::getMax(void) const
{
	return this->_n;
}

std::list<int> Span::getLst(void) const
{
	return this->_l;
}

void Span::addNumber(int a)
{
	if (this->_l.size() >= this->_n)
		throw Span::OutOfRoomException();
	this->_l.push_back(a);
}

unsigned int Span::longestSpan(void)
{
	if (this->_l.size() < 2)
		throw Span::NoSpanException();
	this->_l.sort();
	return this->_l.back() - this->_l.front();
}

unsigned int Span::shortestSpan(void)
{
	if (this->_l.size() < 2)
		throw Span::NoSpanException();
	this->_l.sort();
	std::list<int>::iterator ptr = this->_l.begin();
	ptr++;
	return *ptr -  this->_l.front();
}

const char* Span::NoSpanException::what() const throw()
{
	return "Error: list is too short";
}

const char* Span::OutOfRoomException::what() const throw()
{
	return "Error: list is out of room";
}
