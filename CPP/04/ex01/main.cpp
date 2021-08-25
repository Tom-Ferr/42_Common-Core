/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:16:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 15:05:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main(int argc, char const *argv[]) {

	int size = 10;
 	Animal* meta[size];
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	for (int k = 0; k < size; k++) {
		if (k < size / 2)
			meta[k] = new Animal(*i);
		else
			meta[k] = new Animal(*j);
	}
	for (int k = 0; k < size; k++) {
		delete meta[k];
	}

	delete j;
	delete i;

	return 0;
}
