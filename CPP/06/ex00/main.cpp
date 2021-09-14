/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:47:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/10 18:41:22 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2)
		{std::cout << "Too few arguments" << std::endl; return 1;}
	if (argc > 2)
		{std::cout << "Too many arguments" << std::endl; return 2;}

	Convert c(argv[1]);

	return 0;
}
