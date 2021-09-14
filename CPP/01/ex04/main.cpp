/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:45:39 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/14 13:06:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	if (argc != 4){
		std::cout << "3 arguments are required, no more, no less" << std::endl;
		return 1;
	}

	std::ifstream	ifs(argv[1]);

	if (!ifs)
		return (std::cout << "Error: file not found" << std::endl, 2);

	std::string		outFile = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	if(s1.empty() || s2.empty())
		return (std::cout << "Error: empty string as argument" << std::endl, 3);

	int				pos;
	std::string		line;
	std::ofstream	ofs(outFile.insert(outFile.size(), ".replaced"));

	while (getline(ifs, line))
	{
		while((pos = line.find(s1, 0)) > -1)
		{
			line.erase(pos, s1.size());
			line.insert(pos, s2);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
