/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:34:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 12:02:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	std::cout << *stringPTR << std::endl;
	std::cout << &stringREF << std::endl;


	return 0;
}
