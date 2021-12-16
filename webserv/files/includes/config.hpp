/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:51:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/16 14:23:44 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>

class Config
{
private:
    bool                        _dir_indexing;
    std::string                 _host;
    std::string                 _root;
    std::string                 _index;
    std::string                 _server_name;
    std::string                 _error_page;
    std::string                 _tag;
    size_t                      _client_max_body_size;
    std::vector<std::string>    _port;
    std::vector<Config> _locations;
    std::vector<std::string>    _allowed_methods;

    Config(void);
    Config(std::istream & block);
    void parseConfig(std::istream & ifs);
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
    std::string getTag() const;
    std::vector<std::string> getAllowedMethods() const;
    bool getDirIndexing() const;
    const Config & select(std::string const & dir) const;
};
#endif