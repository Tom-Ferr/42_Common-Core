/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:32:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/29 20:40:39 by tde-cama         ###   ########.fr       */
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
                    
                    size_t i = 0;
                    for(; i < _servers.size(); ++i){
                        if( conf.getHost() == _servers[i].at(0).getHost()
                        && conf.getPort() == _servers[i].at(0).getPort() ){
                            _servers[i].push_back(conf);
                            break ;
                        }
                    }
                    if(i == _servers.size()){
                        Socket  s;
                        Bind    b(s.getSock(), conf);
                        Listen  l(s.getSock());
                        std::vector<Config> vC;
                        vC.push_back(conf);
                        _servers.push_back(vC);
                        _sockets.push_back(s);
                        _binds.push_back(b);
                    }

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

 std::vector<Config> & Server::operator[](size_t const & i){
    if(i >= _servers.size())
       throw Server::FdFailedException();
    return _servers[i];
};

size_t Server::getSize() const{
    return _servers.size();
};

int Server::getSock(size_t const & i) const{
    return _sockets.at(i).getSock();
};

Bind Server::getBind(size_t const & i) const{
    return _binds.at(i);
};

size_t Server::select(size_t const & i, std::string const & host) const{

    size_t j = 0;
    for(; j < _servers[i].size(); ++j){
        if (_servers[i].at(j).getServerName().append("\r") == host)
            break ;
    }
    return j % _servers[i].size();
};