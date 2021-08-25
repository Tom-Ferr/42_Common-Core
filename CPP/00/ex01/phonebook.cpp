/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:11:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/15 21:35:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int argc, char *argv[]) {
	std::string cmd;
	Contact contacts[8];
	int i = 0;

	while (1)
	{
		std::cout << "Waiting for a command" << std::endl;
		getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
		{
			contacts[i % 8].add_contact();
			i++;
		}
		else if (!cmd.compare("SEARCH"))
			search_contact(i, contacts);
		else if (!cmd.compare("EXIT"))
			break;
	}
	return 0;
}
