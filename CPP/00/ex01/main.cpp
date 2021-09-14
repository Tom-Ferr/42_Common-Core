/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:11:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 17:34:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int argc, char *argv[]) {
	std::string cmd;
	PhoneBook phonebook;
	unsigned int i = 0;

	while (!std::cin.eof())
	{
		std::cout << "Waiting for a command" << std::endl;
		getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
		{
			phonebook.contacts[i % 8].add_contact();
			i++;
		}
		else if (!cmd.compare("SEARCH"))
			phonebook.search_contact(i, phonebook.contacts);
		else if (!cmd.compare("EXIT"))
			break;
	}
	if (std::cin.eof())
		std::cout << "EOF signal has been received...Please, avoid pressing ctrl-D" << std::endl;
	return 0;
}
