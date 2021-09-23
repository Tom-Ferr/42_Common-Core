/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:16:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/17 19:34:58 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main()
{
	{
		std::cout << "creating Objs" << std::endl;
		std::cout << "-----------------------" << std::endl;
    	const Animal* j = new Dog();
    	const Animal* i = new Cat();
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting Objs" << std::endl;
		std::cout << "-----------------------" << std::endl;
    	delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		int size = 10;
		Animal* meta[size];

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
	std::cout << std::endl;
	{
		int size = 10;
		Dog* meta[size];
		Dog* copy[size];

		std::cout << "creating Dogs" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			meta[k] = new Dog();
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "copying Dogs" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			copy[k] = new Dog(*(meta[k]));
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting originals" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			delete meta[k];
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "readind copies" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			std::cout << copy[k]->mindReader() << std::endl;
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting copies" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			delete copy[k];
		}
	}
	std::cout << std::endl;
	{
		int size = 10;
		Cat* meta[size];
		Cat* copy[size];

		std::cout << "creating Cats" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			meta[k] = new Cat();
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "copying Cats" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			copy[k] = new Cat(*(meta[k]));
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting originals" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			delete meta[k];
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "readind copies" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			std::cout << copy[k]->mindReader() << std::endl;
		}
		std::cout << "-----------------------" << std::endl;
		std::cout << "deleting copies" << std::endl;
		std::cout << "-----------------------" << std::endl;
		for (int k = 0; k < size; k++) {
			delete copy[k];
		}
	}


	return 0;
}
