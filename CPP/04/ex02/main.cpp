/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:16:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 20:32:25 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main(int argc, char const *argv[]) {

	int size = 10;
 	AAnimal* meta[size];


	for (int k = 0; k < size; k++) {
		if (k < size / 2)
			meta[k] = new Dog();
		else
			meta[k] = new Cat();
	}
	for (int k = 0; k < size; k++) {
		delete meta[k];
	}


	return 0;
}
