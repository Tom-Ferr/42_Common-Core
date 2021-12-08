/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/07 20:36:01 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.hpp>

Config::Config(void){
    return ;
};

Config::Config(std::string const & path) : _host("127.0.0.1"){
    std::ifstream	ifs(path.c_str());
    if (!ifs){
        throw Config::FdFailedException();
    }
    else{
        std::string line;

        size_t option ;
        
        while (std::getline(ifs, line, '{')){
        	if ((option = line.rfind("server")) < std::string::npos){
                if ((option + 5) == line.find_last_not_of(" \n"))
                    parseConfig(ifs);
                else 
                    throw Config::FdFailedException();
            }
        }
        ifs.close();
    }
};

Config::~Config(void){
    return ;
};

Config::Config(Config const & src){
    *this = src;
};

Config & Config::operator=(Config const & rhs){
    if (this != &rhs){
        this->_port= rhs._port;
        this->_host= rhs._host;
    }
    return *this;
};

std::string Config::getHost() const{
    return _host;
};

int Config::getPort() const{
    std::stringstream tar(_port[0]);
    int ret;
    tar >> ret;
    return ret;
};

std::string Config::getRoot() const{
    return _root;
};
std::string Config::getIndex() const{
    return _index;
};
std::string Config::getServerName() const{
    return _server_name;
};

const char* Config::FdFailedException::what() const throw(){
    return "configuration file was not found";
};

void Config::parseConfig(std::ifstream & ifs){
    std::string line;
    std::stringstream token;
    while (std::getline(ifs, line, ';')){
        token.clear();
        token << line;
        while (std::getline(token, line, ' ')){
            if (!line.compare("listen")){
                std::getline(token, line, ' ');
                _port.push_back(line);
            }
            else if (!line.compare("host")){
                std::getline(token, line, ' ');
                _host = line;
            }
            else if (!line.compare("root")){
                std::getline(token, line, ' ');
                _root = line;
            }
            else if (!line.compare("index")){
                std::getline(token, line, ' ');
                _index = line;
            }
            else if (!line.compare("server_name")){
                std::getline(token, line, ' ');
                _server_name = line;
            }
        }
    }
};
