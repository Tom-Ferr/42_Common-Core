/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_parser.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/30 22:22:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <request_parser.hpp>

Req_Parser::Req_Parser(void){
    return ;
};

Req_Parser::Req_Parser(Receive const & re)
    : _req(re.bin()), _sock(re.getSock())  {

    std::stringstream s_req(_req);
    std::string token;
    std::getline(s_req, token, ' ');
    _method = token;
    std::getline(s_req, token, ' ');
    _file = token;
    std::getline(s_req, token, '\r');
    _version = token;
    
    std::string data;
    while (std::getline(s_req, token, '\r')){
        if(!token.compare("\n")){
            std::getline(s_req, token, '\n');
            break ;
        }
        if(token.find("Host") < std::string::npos){
            std::stringstream doi(token);
            std::getline(doi, data, ' ');
            std::getline(doi, data, ' ');
            _host = data;
        }
        else if(token.find("Content-Type") < std::string::npos){
            std::stringstream doi(token);
            std::getline(doi, data, ' ');
            std::getline(doi, data, ' ');
            _type = data;
        }
        else if(token.find("Transfer-Encoding") < std::string::npos){
            std::stringstream doi(token);
            std::getline(doi, data, ' ');
            std::getline(doi, data, ' ');
            _trans_enc = data;
        }
        else if(token.find("Content-Length") < std::string::npos){
            std::stringstream doi(token);
            std::getline(doi, data, ' ');
            std::getline(doi, data, ' ');
            std::stringstream conv(data);
            conv >> _body_len;
        }
    }
    
    if(!_method.compare("POST")){
        
        size_t not_read = _body_len;

        while(not_read > 0){
            char buffer[not_read];
            size_t bytes = recv(_sock, buffer, not_read, 0);
            _body.append(buffer, bytes);
            not_read -= bytes;
        }
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
        this->_body = rhs._body;
        this->_host = rhs._host;
        this->_trans_enc = rhs._trans_enc;
        this->_body_len = rhs._body_len;
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

std::string Req_Parser::getHost() const{
    return _host;
};

size_t Req_Parser::getBodyLen() const{
    return _body_len;
};