/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_parser.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/17 12:27:58 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <request_parser.hpp>

Req_Parser::Req_Parser(void){
    return ;
};

Req_Parser::Req_Parser(char const *buffer)
    : _req(buffer){
    std::stringstream s_req(_req);
    std::string token;
    std::getline(s_req, token, ' ');
    _method = token;
    std::getline(s_req, token, ' ');
    _file = token;
    std::getline(s_req, token, '\r');
    _version = token;

    if(!_method.compare("POST")){
        std::string data;
        std::getline(s_req, token, '{');
        std::stringstream head(token);
        while (std::getline(head, token, '\n')){
            if(token.find("Content-Type") < std::string::npos){
                std::stringstream doi(token);
                std::getline(doi, data, ' ');
                std::getline(doi, data, ' ');
                _type = data;
            }
            else if(token.find("Content-Length") < std::string::npos){
                std::stringstream doi(token);
                std::getline(doi, data, ' ');
                std::getline(doi, data, ' ');
                std::stringstream conv(data);
                conv >> _body_len;
            }
        }
        std::getline(s_req, token, '}');
        _body = token;
    }
};

Req_Parser::~Req_Parser(void){
    return ;
};

Req_Parser::Req_Parser(Req_Parser const & src){
    *this = src;
};

Req_Parser & Req_Parser::operator=(Req_Parser const & rhs){
    if (this != &rhs){
        this->_req = rhs._req;
        this->_method = rhs._method;
        this->_file = rhs._file;
        this->_version = rhs._version;
        this->_type = rhs._type;
    }
    return *this;
};

std::string Req_Parser::getFile() const{
    return _file;
};

std::string Req_Parser::getVersion() const{
    return _version;
};

std::string Req_Parser::getType() const{
    return _type;
};

std::string Req_Parser::getMethod() const{
    return _method;
};

std::string Req_Parser::getBody() const{
    return _body;
};

size_t Req_Parser::getBodyLen() const{
    return _body_len;
};