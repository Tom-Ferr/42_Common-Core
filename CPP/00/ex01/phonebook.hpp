/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:24:09 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/15 20:34:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_HPP
# define  PHILO_BONUS_HPP

# include <iostream>
# include <cstring>
# include <string>
# include <unistd.h>

class Contact
{
public:
	std::string firstname, lastname, nickname;
	std::string phone;
	std::string dark_secret;

	void add_contact(void);
};

void search_contact(int i, Contact contacts[]);

#endif
