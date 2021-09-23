/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:16:24 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/15 20:09:42 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char const *argv[]){
	if (argc == 1)
	{
		std::cout << "[Ops]" << std::endl;
		std::cout << "An argument is needed!" << std::endl;
		return 1;
	}
	std::string msn[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Karen k;
	int i;
	for (i = 0; i <= 4; i++) {
		if (!msn[i].compare(argv[1]))
			break;
	}
	switch (i) {
		case 0:
			k.complain(msn[0]);
		case 1:
			k.complain(msn[1]);
		case 2:
			k.complain(msn[2]);
		case 3:
			k.complain(msn[3]);
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
