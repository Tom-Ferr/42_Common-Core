/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:16:24 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 23:53:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char const *argv[]){
	std::string msn[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Karen k;
	int i;
	for (i = 0; i < 4; i++) {
		if (!msn[i].compare(argv[1]))
			break;
	}
	if (i >= 4)
		return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 0)
	for (int j = 0; j < 4; j++) {
		if (j >= i)
			k.complain(msn[j]);
	}
	return 0;
}
