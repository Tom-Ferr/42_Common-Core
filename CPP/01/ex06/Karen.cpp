/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:12:12 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 16:45:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	return ;
}

Karen::~Karen(void)
{
	return ;
}

void Karen::debug( void ) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon  for my 7XL-double-cheese";
	std::cout << "-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;
}
void Karen::info( void ) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << " You don’t put enough!" << std::endl;
	std::cout << " If you did I would not have to ask for it!" << std::endl;

}
void Karen::warning( void ) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << " I’ve been coming here for years";
	std::cout << " and you just started working here last month." << std::endl;
}
void Karen::error( void ) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable,";
	std::cout << " I want to speak to the manager now." << std::endl;
}

void Karen::complain( std::string level )
{
	std::string msn[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Karen::funcs fc[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++){
		if (level == msn[i]){
			(this->*fc[i])();
			return ;
		}
	}
}
