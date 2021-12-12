/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/12 14:19:20 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <response.hpp>

Response::Response(void){
    return ;
};

Response::Response(Req_File const & file, Req_Parser const & req){
    std::stringstream conv;
    if(req.getFile().find(".css") < std::string::npos)
        _type = "text/css";
    else if(req.getFile().find(".jpg") < std::string::npos)
        _type = "image/jpeg";
    else /*(req.getFile().find(".html") < std::string::npos)*/
        _type = "text/html";
    _res = req.getVersion() + " " + file.getStatus() + "\n";
    _res += "Content-Type: " + _type;
    if (_res.find("text/") < std::string::npos)
        _res += ";charset=UTF-8";
    _res += "\nContent-Length: ";
    conv << file.getSize();
    conv >> _len;
    _res += _len;
    _res += "\r\n\r\n";
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
