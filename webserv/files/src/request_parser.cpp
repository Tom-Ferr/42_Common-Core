/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_parser.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/08 13:37:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <request_parser.hpp>

Req_Parser::Req_Parser(void){
    return ;
};

Req_Parser::Req_Parser(char const *buffer, std::string const & index)
    : _req(buffer), _index(index){
    std::stringstream s_req(_req);
    std::string token;
    std::getline(s_req, token, ' ');
    _method = token;
    std::getline(s_req, token, ' ');
    _file = token;
    std::getline(s_req, token, '\r');
    _version = token;
    // while(std::getline(s_req, token)){
    //     std::stringstream s_tok(token);
    //     std::getline(s_tok, token, ' ');
    //     if(!token.compare("Accept:")){
    //         std::getline(s_tok, token, ',');
    //         _type = token;
    //     }

    // }
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
        this->_index = rhs._index;
        this->_method = rhs._method;
        this->_file = rhs._file;
        this->_version = rhs._version;
    }
    return *this;
};

std::string Req_Parser::getFile() const{
    if (!_file.compare("/"))
        return _file + _index;
    return _file;
};

std::string Req_Parser::getVersion() const{
    return _version;
};

std::string Req_Parser::getType() const{
    return _type;
};