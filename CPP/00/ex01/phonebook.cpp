/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:45:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 17:37:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::get_contact(unsigned int const &i, Contact contacts[])
{
	std::string index;

	std::cout << "Please, insert contact's index" << std::endl;
	getline(std::cin, index);
	if (index.empty() || index.size() > 1 || index.at(0) < '0'
	|| (index.at(0) - '0') > (i - 1) % 8 || !index.at(0))
	{
		std::cout << "Not a valid input, try again? [Y/N]" << std::endl;
		while (1)
		{
			if (std::cin.eof())
				return ;
			getline(std::cin, index);
			if (index.size() == 1 && (index.at(0) == 'Y' || index.at(0) == 'N'))
				break ;
			std::cout << "\e[A" << '\r' << "\e[2K";
		}
		if (index.at(0) == 'Y')
			search_contact(i, this->contacts);
	}
	else
	{
		std::cout << "Contact #" << index.at(0) << std::endl;
		*index.begin() = index.at(0) - '0';
		std::cout << "First Name: " << this->contacts[index.at(0)].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->contacts[index.at(0)].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[index.at(0)].getNicktName() << std::endl;
		std::cout << "Phone: " << this->contacts[index.at(0)].getPhone() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[index.at(0)].getSecret() << std::endl;
		std::cout << "/----------------------------/" << std::endl;
	}
}

void PhoneBook::write_name(std::string name)
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

void PhoneBook::search_contact(unsigned int const &i, Contact contacts[])
{
	char k = 9;

	if (!i)
		std::cout << "PhoneBook is EMPTY" << std::endl;
	else
	{
		for (int j = 0; j < i && j < 8; j++)
		{
			while (k--)
			std::cout << ' ';
			std::cout << j;
			std::cout << '|';
			write_name(this->contacts[j].getFirstName());
			std::cout << '|';
			write_name(this->contacts[j].getLastName());
			std::cout << '|';
			write_name(this->contacts[j].getNicktName());
			std::cout << std::endl;
			k = 9;
		}
		get_contact(i, this->contacts);
	}
}
