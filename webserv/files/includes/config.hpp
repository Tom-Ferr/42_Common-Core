/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:51:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/07 18:20:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include <vector>

class Config
{
private:
    std::vector<std::string> _port;
    std::string _host;
    std::string _root;
    std::string _index;
    std::string _server_name;
    Config(void);
    void parseConfig(std::ifstream & ifs);
    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
public:
    Config(std::string const & path);
    ~Config();
    Config(Config const & src);
    Config & operator=(Config const & rhs);

    std::string getHost() const;
    int getPort() const;
    std::string getRoot() const;
    std::string getIndex() const;
    std::string getServerName() const;
};
#endif