/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_parser.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/07 18:45:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <request_parser.hpp>

Req_Parser::Req_Parser(void){
    return ;
};

Req_Parser::Req_Parser(char const *buffer, std::string const & index)
    : _req(buffer), _index(index){
    
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
    }
    return *this;
};

std::string Req_Parser::getFile() const{
    int i = 0;
    std::stringstream s_req(_req);
    std::string token;
    while (std::getline(s_req, token, ' ')){
        if (i){
            if (!token.compare("/"))
                token = _index;
            return token;
        }
        i++;
    }
    return token;
};