/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/30 21:01:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.hpp>
#include <iostream>

Config::Config(void){
    return ;
};

Config::Config(std::istream & ifs)
    : _dir_indexing(false), _client_max_body_size(ULLONG_MAX), _host("0.0.0.0"), _port("80"){
        parseConfig(ifs);
};

Config::Config(std::istream & block, Config const & mother)
    :  _dir_indexing(false), _client_max_body_size(ULLONG_MAX), _root(mother.getRoot()),
    _error_page(mother.getErrorPages()), _upload(mother.getUpload()){
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
        this->_redirection = rhs._redirection;
        this->_locations  = rhs._locations;
        this->_allowed_methods  = rhs._allowed_methods;
        this->_cgi_list  = rhs._cgi_list;
        this->_upload  = rhs._upload;
    }
    return *this;
};

std::string Config::getHost() const{
    return _host;
};

int Config::getPort() const{
    std::stringstream tar(_port);
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

std::string Config::getRedirection() const{
    return _redirection;
};

std::string Config::getErrorPages() const{
    return _error_page;
};

std::string Config::getUpload() const{
    return _upload;
};

size_t Config::getMaxBody() const{
    return _client_max_body_size;
};

bool Config::getDirIndexing() const{
    return _dir_indexing;
};

std::vector<std::string> Config::getCgiList() const{
    return _cgi_list;
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
                    _port = line;
                }
                else
                    _port = line;
            }
            else if (!line.compare("port")){
                std::getline(token, line, ' ');
                _port = line;
            }
            else if (!line.compare("host")){
                std::getline(token, line, ' ');
                _host = line;
            }
            else if (!line.compare("root")){
                std::getline(token, line, ' ');
                _root = line;
                _upload = line;
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
            else if (!line.compare("return")){
                std::getline(token, line, ' ');
                _redirection = line;
            }
            else if (!line.compare("allowed_methods")){
                while (std::getline(token, line, ' ')){
                    if(line.compare(" "))
                    _allowed_methods.push_back(line);
                }
            }
            else if (!line.compare("is_cgi")){
                while (std::getline(token, line, ' ')){
                    if(line.compare(" "))
                    _cgi_list.push_back(line);
                }
            }
            else if (!line.compare("save_at")){
                std::getline(token, line, ' ');
                _upload += line;
            }
        }
    }
};

const Config & Config::select(std::string const & dir) const{
    size_t index = 0;
    if(_locations.size()){
        for (size_t i = 0; i < _locations.size(); ++i){
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

bool Config::checkCgi(std::string const & target) const{
    size_t dot = target.length() - 3;
    for (size_t i = 0; i < _cgi_list.size(); ++i){
        if(target.rfind(_cgi_list[i], dot) < std::string::npos)
            return true;
    }
    return false;
}
