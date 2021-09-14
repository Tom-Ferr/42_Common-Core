/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:24:09 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/13 18:30:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define  PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <string>
# include <unistd.h>

class Contact
{
private:
	std::string firstname, lastname, nickname;
	std::string phone;
	std::string dark_secret;
public:

	void add_contact(void);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNicktName(void);
	std::string getPhone(void);
	std::string getSecret(void);
};

class PhoneBook
{
private:
	void write_name(std::string name);
	void get_contact(unsigned int const &i, Contact contacts[]);
public:
	Contact contacts[8];
	void search_contact(unsigned int const &i, Contact contacts[]);
};


#endif
