/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:23:20 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/14 14:04:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				if (std::islower(argv[i][j]))
					argv[i][j] -= 32;
			std::cout << argv[i];
			if (argv[i + 1])
				std::cout << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
