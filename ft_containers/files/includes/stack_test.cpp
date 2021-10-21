/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:43:51 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/21 15:09:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_CPP
# define STACK_TEST_CPP
std::cout << "::::::::::::::: STACK :::::::::::::::" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "•••• Constructor ••••" << std::endl;
	std::cout << std::endl;
	{
		std::cout << "Test 1: Default Constructor" << std::endl;
		std::cout << std::endl;
		ft::stack<int>stk;
		std::cout << "pre size: " << stk.size() << std::endl;
		for (size_t i = 0; i < 1000; i++){
			stk.push(i);
		}
		std::cout << "post size: " << stk.size() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "•••• Capacity ••••" << std::endl;
	std::cout << std::endl;
	{
		std::cout << std::endl;
		{
			std::cout << "Test 2: Empty" << std::endl;
			std::cout << std::endl;

			ft::stack<int> stk;

			std::cout <<"Should return 1 as True: ";
			std::cout << stk.empty() << std::endl;

			stk.push(42);

			std::cout <<"Should return 0 as False: ";
			std::cout << stk.empty() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "•••• Element Access ••••" << std::endl;
	std::cout << std::endl;
	{

		std::cout << "Test 1 Top" << std::endl;
			std::cout << std::endl;

		ft::stack<int> stk;
		for (size_t i = 0; i < 10; i++){
			stk.push(i);
		}

		std::cout << "top of stack is: " << stk.top() << std::endl;
		
	}	
	std::cout << std::endl;
	std::cout << "•••• Modifiers ••••" << std::endl;
	std::cout << std::endl;
		{
			std::cout << "Test 1 Push" << std::endl;
			std::cout << std::endl;

			ft::stack<int>stk;

			std::cout << "pre size: " << stk.size() << std::endl;
			std::cout << "----------------" << std::endl;

			for (size_t i = 0; i < 1000; i++){
				stk.push(i);
			}
			std::cout << "post size: " << stk.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << std::endl;

			std::cout << "Test 2 Pop Back" << std::endl;
			std::cout << std::endl;

			std::cout << "pre size: " << stk.size() << std::endl;
			std::cout << "----------------" << std::endl;

			for (size_t i = stk.size() - 1; i ; i--){
				stk.pop();
			}
			std::cout << "post size: " << stk.size() << std::endl;
			std::cout << "----------------" << std::endl;

		}
		std::cout << std::endl;
		std::cout << "•••• Non-Member ••••" << std::endl;
		std::cout << std::endl;
		{
			std::cout << std::endl;

			ft::stack<int> small;
			ft::stack<int> big;

			for (size_t i = 0; i < 50; i++)
			{
				big.push(std::rand());
			}
			for (size_t i = 0; i < 10; i++)
			{
				small.push(std::rand());
			}
			
			if (big == big)
				std::cout << "equal overload ok" << std::endl;
			if (big != small)
				std::cout << "non equal overload ok" << std::endl;
			if (big > small)
				std::cout << "bigger than overload ok" << std::endl;
			if (small < big)
				std::cout << "smaller than overload ok" << std::endl;
			if (big >= big && big >= small)
				std::cout << "bigger or equal overload ok" << std::endl;
			if (small <= small && small <= big)
				std::cout << "smaller or equal overload ok" << std::endl;

			std::cout << std::endl;
		
		
		}

#endif
