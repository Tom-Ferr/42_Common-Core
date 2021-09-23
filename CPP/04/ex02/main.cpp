/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:16:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 20:20:31 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main()
{
	{
		std::cout << "creating Objs" << std::endl;
		std::cout << "-----------------------" << std::endl;
    	const AAnimal* j = new Dog();
    	const AAnimal* i = new Cat();
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting Objs" << std::endl;
		std::cout << "-----------------------" << std::endl;
    	delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		int size = 10;
		AAnimal* meta[size];

		std::cout << "creating Cat/Dog" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			if (k < size / 2)
			meta[k] = new Cat();
			else
			meta[k] = new Dog();
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting Cat/Dog" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			delete meta[k];
		}
	}


	return 0;
}
