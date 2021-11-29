/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/29 17:58:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <response.hpp>

Response::Response(void){
    return ;
};

Response::Response(std::string const & content){
    std::stringstream conv;
    std::string len;
    _res = "HTTP/1.1 200 OK\nContent-Type: text/html;charset=UTF-8\nContent-Length: ";
    conv << content.length();
    conv >> len;
    _res += len;
    _res += "\n\n";
    _res += content;
};

Response::~Response(void){
    return ;
};

Response::Response(Response const & src){
    *this = src;
};

Response & Response::operator=(Response const & rhs){
    if (this != &rhs){
        this->_res = rhs._res;
    }
    return *this;
};

std::string Response::getResponse() const{
    return _res;
};

size_t Response::getSize() const{
    return _res.length();
};
