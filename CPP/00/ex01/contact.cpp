/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:25:45 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/13 17:38:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::add_contact(void)
{
	std::cout << "First Name:" << std::endl;
	getline(std::cin, this->firstname);
	std::cout << "Last Name:" << std::endl;
	getline(std::cin, this->lastname);
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, this->nickname);
	std::cout << "Phone:" << std::endl;
	getline(std::cin, this->phone);
	std::cout << "Darkest Secret:" << std::endl;
	getline(std::cin, this->dark_secret);
}

std::string Contact::getFirstName(void)
{
	return this->firstname;
}

std::string Contact::getLastName(void)
{
	return this->lastname;
}

std::string Contact::getNicktName(void)
{
	return this->nickname;
}

std::string Contact::getPhone(void)
{
	return this->phone;
}

std::string Contact::getSecret(void)
{
	return this->dark_secret;
}
