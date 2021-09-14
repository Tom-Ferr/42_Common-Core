/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:29:28 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/11 10:53:08 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(char* target) : _s(target), _i(0), _c(0), _f(0), _d(0)
{

	int size = this->_s.size(), pm = this->_s.find_last_of("+-");

	if (!this->_s.compare("nan") || !this->_s.compare("-inf")
	|| !this->_s.compare("+inf") || !this->_s.compare("inf")
	|| !this->_s.compare("nanf") || !this->_s.compare("-inff")
	|| !this->_s.compare("+inff") || !this->_s.compare("inff"))
		Convert::PseudosHandler(size);
	else if ((this->_s.find_first_not_of("0123456789.f-+") < size && size > 1)
	|| (this->_s.find_first_of("f") < size - 1 || (pm > 0 && pm < size)))
		Convert::NonSense();
	else {
		Convert::Detect();
		Convert::Cast();
		Convert::Format();
	}
	Convert::Print();
}

Convert::Convert(Convert const & src)
{
	*this = src;
}

Convert & Convert::operator=(Convert const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Convert::~Convert()
{
	return ;
}

void Convert::Detect(void)
{
	if ((this->_s.at(0) < '0' || this->_s.at(0) > '9') && this->_s.size() == 1)
	{
		std::stringstream detector(this->_s);
		detector >> this->_c;
	}
	else if (this->_s.find('f', 0) < this->_s.size())
	{
		this->_s.pop_back();
		std::stringstream detector(this->_s);
		detector >> this->_f;
	}
	else if (this->_s.find('.', 0) < this->_s.size())
	{
		std::stringstream detector(this->_s);
		detector >> this->_d;
	}
	else
	{
		std::stringstream detector(this->_s);
		detector >> this->_i;
	}
}

void Convert::Cast(void)
{
	if (this->_c)
	{
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
	}
	else if (this->_f)
	{
		this->_i = static_cast<int>(this->_f);
		this->_c = static_cast<char>(this->_f);
		this->_d = static_cast<double>(this->_f);
	}
	else if (this->_d)
	{
		this->_i = static_cast<int>(this->_d);
		this->_c = static_cast<char>(this->_d);
		this->_f = static_cast<float>(this->_d);
	}
	else
	{
		this->_f = static_cast<float>(this->_i);
		this->_c = static_cast<char>(this->_i);
		this->_d = static_cast<double>(this->_i);
	}
}

void Convert::PseudosHandler(int const & size)
{
	this->_oc = "impossible";
	this->_oi = "impossible";
	this->_od = this->_s;
	this->_of = this->_s;
	if (this->_s.find_first_of("f") == size - 1)
		this->_of.append("f");
	else
		this->_od.pop_back();
}

void Convert::NonSense()
{
	this->_oc = "impossible";
	this->_oi = "impossible";
	this->_od = "impossible";
	this->_of = "impossible";
}

void Convert::Format(void)
{
	std::stringstream i, c, f, d;

	if (this->_c < 32 || this->_c > 126)
		this->_oc = "Non displayable";
	else {
		c << this->_c;
		this->_oc = "\'";
		this->_oc.append(c.str());
		this->_oc.append("\'");
	}

	d << this->_d;
	f << this->_f;
	i << this->_i;

	if (this->_i > CHAR_MAX || this->_i < CHAR_MIN)
		this->_oc = "impossible";
	if ((this->_i == INT_MAX && this->_s.compare("2147483647"))
	||	(this->_i == INT_MIN && this->_s.compare("-2147483648")))
		this->_oi = "impossible";
	else
		this->_oi = i.str();
	this->_od = d.str();
	this->_of = f.str();

	if (this->_od.find_first_not_of("0123456789") > this->_od.size())
		this->_od.append(".0");

	if (this->_of.find_first_not_of("0123456789") > this->_of.size())
		this->_of.append(".0");
	this->_of.append("f");
}

void Convert::Print(void)
{
	std::cout << "char: " << this->_oc << std::endl;
	std::cout << "int: " << this->_oi << std::endl;
	std::cout << "float: " << this->_of << std::endl;
	std::cout << "double: " << this->_od << std::endl;
}
