/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:16:24 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/16 23:33:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(){
	std::string msn[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Karen k;
	for (int i = 0; i < 20; i++) {
		k.complain(msn[std::rand()%4]);
	}
	return 0;
}
