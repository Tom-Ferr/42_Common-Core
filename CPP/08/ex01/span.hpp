/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:01:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/22 10:19:29 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>

class Span
{
	class OutOfRoomException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	Span(void);
public:
	Span(unsigned int const n);
	Span(Span const & src);
	~Span(void);
	Span & operator=(Span const & rhs);

	typedef std::list<int>::iterator iterator;

	std::list<int> getLst(void) const;
	unsigned int getMax(void) const;

	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	void addNumber(int a);

	iterator begin(void);
	iterator end(void);

private:
	unsigned int _n;
	std::list<int> _l;

};
#endif
