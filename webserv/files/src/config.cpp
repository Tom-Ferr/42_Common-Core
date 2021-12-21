/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/21 11:57:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.hpp>

Config::Config(void){
    return ;
};

Config::Config(std::string const & path)
    : _dir_indexing(false), _client_max_body_size(ULLONG_MAX), _host("127.0.0.1"){
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

Config::Config(std::istream & block, Config const & mother)
    : _client_max_body_size(ULLONG_MAX), _root(mother.getRoot()){
        parseConfig(block);
};

Config::~Config(void){
    return ;
};

Config::Config(Config const & src){
    *this = src;
};

Config & Config::operator=(Config const & rhs){
    if (this != &rhs){
        this->_dir_indexing = rhs._dir_indexing;
        this->_host = rhs._host;
        this->_root = rhs._root;
        this->_index = rhs._index;
        this->_server_name = rhs._server_name;
        this->_error_page = rhs._error_page;
        this->_client_max_body_size = rhs._client_max_body_size;
        this->_port = rhs._port;
        this->_tag = rhs._tag;
        this->_locations  = rhs._locations;
        this->_allowed_methods  = rhs._allowed_methods;
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

std::string Config::getTag() const{
    return _tag;
};

size_t Config::getMaxBody() const{
    return _client_max_body_size;
};

bool Config::getDirIndexing() const{
    return _dir_indexing;
};

std::vector<std::string> Config::getAllowedMethods() const{
    return _allowed_methods;
};

const char* Config::FdFailedException::what() const throw(){
    return "configuration file was not found";
};

void Config::parseConfig(std::istream & ifs){
    std::string line;
    std::stringstream token;
    while (std::getline(ifs, line, ';')){
        std::stringstream token;
        token << line;
        if(line.find("#") < std::string::npos){
            std::getline(ifs, line, '\n');
            continue ;
        }
        if(line.find("}") < std::string::npos)
            break ;
        while (std::getline(token, line, ' ')){
            if (!line.compare("listen")){
                std::getline(token, line, ' ');
                if(line.find(":") < std::string::npos){
                    token.clear();
                    token << line;
                    std::getline(token, line, ':');
                    _host = line;
                    std::getline(token, line, ' ');
                    _port.push_back(line);
                }
                else
                    _port.push_back(line);
            }
            else if (!line.compare("port")){
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
            else if (!line.compare("location")){
                std::getline(token, line, ' ');
                std::string loc = line;
                std::getline(token, line, '{');
                std::getline(ifs, line, '}');
                token << ";";
                token << line;
                Config loc_conf(token, *this);
                _locations.push_back(loc_conf);
                _locations.back()._tag = loc;
            }
            else if (!line.compare("auto_index")){
                std::getline(token, line, ' ');
                if(!line.compare("on"))
                    _dir_indexing = true;
            }
            else if (!line.compare("client_max_body_size")){
                std::getline(token, line, ' ');
                std::stringstream conv;
                conv << line;
                conv >> _client_max_body_size;
            }
            else if (!line.compare("error_page")){
                std::getline(token, line, ' ');
                _error_page = line;
            }
            else if (!line.compare("allowed_methods")){
                while (std::getline(token, line, ' ')){
                    if(line.compare(" "))
                    _allowed_methods.push_back(line);
                }
            }
        }
    }
};

const Config & Config::select(std::string const & dir) const{
    size_t index = 0;
    if(_locations.size()){
        for (size_t i = 0; i < _locations.size(); i++){
            if (_locations.at(i).getTag() == dir || _locations.at(i).getTag() + "/" == dir){
                index = i;
                break ;
            }
        }
        return _locations[index] ;
    }
    else
        return *this ;
};
