/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:11:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/22 13:38:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <list>

int main( void )
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "-------------------" << std::endl;
		std::cout << "test iter" << std::endl;
		std::cout << "-------------------" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "-------------------" << std::endl;
		std::cout << "test copy" << std::endl;
		std::cout << "-------------------" << std::endl;
		while(s.size())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	std::cout << "-------------------" << std::endl;
	std::cout << "other type" << std::endl;
	std::cout << "-------------------" << std::endl;
	{
		MutantStack<double> mstack;
		mstack.push(5.6);
		mstack.push(17.4);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3.3);
		mstack.push(5.5);
		mstack.push(737.9);
		MutantStack<double>::iterator it = mstack.begin();
		MutantStack<double>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "-------------------" << std::endl;
		std::cout << "test iter" << std::endl;
		std::cout << "-------------------" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<double> s(mstack);
		std::cout << "-------------------" << std::endl;
		std::cout << "test copy" << std::endl;
		std::cout << "-------------------" << std::endl;
		while(s.size())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	std::cout << "-------------------" << std::endl;
	std::cout << "More elements" << std::endl;
	std::cout << "-------------------" << std::endl;
	{
		MutantStack<int> mstack;
		for (size_t i = 0; i < 300; i++) {
			mstack.push(std::rand());
		}
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
	    	std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
