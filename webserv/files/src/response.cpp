/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/02 11:13:31 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <response.hpp>

Response::Response(void){
    return ;
};

Response::Response(Req_File const & file){
    std::stringstream conv;
    std::string len;
    _res = "HTTP/1.1 " + file.getStatus() + "\n";
    _res += "Content-Type: text/html;charset=UTF-8\nContent-Length: ";
    conv << file.getContent().length();
    conv >> len;
    _res += len;
    _res += "\n\n";
    _res += file.getContent();
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
