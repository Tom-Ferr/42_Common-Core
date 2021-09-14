/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:44:11 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/11 12:56:45 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <stdlib.h>
#include <time.h>

Base* generate(void)
{
	Base* ret;
	srand(time(NULL));
	int i = rand() % 3;
	if (!i)
		ret = new A;
	else if (i == 1)
		ret = new B;
	else
		ret = new C;
	return ret;
}

void identify(Base* p)
{
	if (A* type = dynamic_cast<A*>(p))
		std::cout << "Points to an Object of Type A" << std::endl;
	else if (B* type = dynamic_cast<B*>(p))
		std::cout << "Points to an Object of Type B" << std::endl;
	else if (C* type = dynamic_cast<C*>(p))
		std::cout << "Points to an Object of Type C" << std::endl;
	else
		std::cout << "Points to an Object of Unknown Type" << std::endl;
}

void identify(Base& p)
{
	bool found = false;
	try
	{
		A type = dynamic_cast<A&>(p);
		found = true;
		std::cout << "Object is of Type A" << std::endl;
	}
	catch (std::exception & e){}
	try
	{
		B type = dynamic_cast<B&>(p);
		found = true;
		std::cout << "Object is of Type B" << std::endl;
	}
	catch (std::exception & e){}
	try
	{
		C type = dynamic_cast<C&>(p);
		found = true;
		std::cout << "Object is of Type C" << std::endl;
	}
	catch (std::exception & e){}
	if (!found)
		std::cout << "Object is of Unknown Type" << std::endl;
}
int main()
{
	Base* p = generate();
	identify(p);
	identify(*p);
	return 0;
}
