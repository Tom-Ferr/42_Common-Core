/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:16:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/19 12:37:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main(int argc, char const *argv[]) {
	const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}
