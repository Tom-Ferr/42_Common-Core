/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:32:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/28 15:55:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.hpp>

Server::Server(std::string const & path){
    std::ifstream	ifs(path.c_str());
    if (!ifs){
        throw Server::FdFailedException();
    }
    else{
        std::string line;

        size_t option ;
        
        while (std::getline(ifs, line, '{')){
        	if ((option = line.rfind("server")) < std::string::npos){
                if ((option + 5) == line.find_last_not_of(" \n")){
                    Config conf(ifs);
                    _servers.push_back(conf);
                }
                else 
                    throw Server::SyntaxErrorException();
            }
        }
        ifs.close();
    }
};

Server::~Server(void){
    return ;
};

Server::Server(Server const & src){
    *this = src;
};

Server & Server::operator=(Server const & rhs){

    if (this != &rhs){
        this->_servers = rhs._servers;
    }
    
    return *this;
};

const char* Server::FdFailedException::what() const throw(){
    return "configuration file was not found";
};

const char* Server::SyntaxErrorException::what() const throw(){
    return "configuration file could not be read due to a syntax error";
};

Config & Server::operator[](size_t i){
    if(i >= _servers.size())
       throw Server::FdFailedException();
    return _servers.at(i);
};

size_t Server::getSize() const{
    return _servers.size();
};