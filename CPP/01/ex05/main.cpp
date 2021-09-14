/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:16:24 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 13:33:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(){
	std::string msn[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Karen k;
	std::srand(std::time(0));
	for (int i = 0; i < 20; i++) {
		k.complain(msn[std::rand()%4]);
	}
	return 0;
}
