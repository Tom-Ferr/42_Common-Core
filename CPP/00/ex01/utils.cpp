/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:45:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/15 22:34:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::add_contact(void)
{
	std::cout << "First Name:" << std::endl;
	getline(std::cin, this->firstname);
	std::cout << "Last Name:" << std::endl;
	getline(std::cin, lastname);
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, nickname);
	std::cout << "Phone:" << std::endl;
	getline(std::cin, phone);
	std::cout << "Darkest Secret:" << std::endl;
	getline(std::cin, dark_secret);
}

void get_contact(int i, Contact contacts[])
{
	char index[2];

		std::cout << "Please, insert contact's index" << std::endl;
		std::cin.getline(index, 2);
		if (strlen(index) > 1 || (index[0] - '0') > (i - 1) % 8 || !index[0])
		{
			std::cout << "Not a valid input, try again? [Y/N]" << std::endl;
			while (1)
			{
				std::cin.getline(index, 2);
				if (strlen(index) == 1 && (index[0] == 'Y' || index[0] == 'N'))
					break ;
				std::cout << "\e[A" << '\r' << "\e[2K";
			}
			if (index[0] == 'Y')
				search_contact(i, contacts);
		}
		else
		{
			std::cout << "Contact #" << index[0] << std::endl;
			index[0] = index[0] - '0';
			std::cout << "First Name: " << contacts[index[0]].firstname << std::endl;
			std::cout << "Last Name: " << contacts[index[0]].lastname << std::endl;
			std::cout << "Nickname: " << contacts[index[0]].nickname << std::endl;
			std::cout << "Phone: " << contacts[index[0]].phone << std::endl;
			std::cout << "Darkest Secret: " << contacts[index[0]].dark_secret << std::endl;
			std::cout << "/----------------------------/" << std::endl;
		}
}

void write_name(std::string name)
{
	int len;

	len = name.size();
	if (10 - len < 0)
	{
		name.resize(9);
		name.push_back('.');
		std::cout << name;
	}
	else
	{
		len = 10 - len;
		while (len)
		{
			std::cout << ' ';
			len--;
		}
		std::cout << name;
	}
}

void search_contact(int i, Contact contacts[])
{
	char k = 9;

	if (!i)
		std::cout << "PhoneBook is EMPTY" << std::endl;
	else
	{
		for (int j = 0; j < i % 8; j++)
		{
			while (k--)
			std::cout << ' ';
			std::cout << j;
			std::cout << '|';
			write_name(contacts[j].firstname);
			std::cout << '|';
			write_name(contacts[j].lastname);
			std::cout << '|';
			write_name(contacts[j].nickname);
			std::cout << std::endl;
			k = 9;
		}
		get_contact(i, contacts);
	}
}
