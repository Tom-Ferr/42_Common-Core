/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requested_file.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/07 10:21:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <requested_file.hpp>

Req_File::Req_File(void){
    return ;
};

Req_File::Req_File(std::string const & target){
    std::ifstream	ifs(target.c_str());
    if (!ifs){
        _content = "<html><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL /t.html was not found on this server.</p></body></html>";
        _status = "404 Not Found";
    }
    else{
        std::string line;
        while (std::getline(ifs, line)){
        	_content += line;
        }
        _status = "200 OK";
        ifs.close();
    }
    _size = _content.length();
};

Req_File::~Req_File(void){
    return ;
};

Req_File::Req_File(Req_File const & src){
    *this = src;
};

Req_File & Req_File::operator=(Req_File const & rhs){
    if (this != &rhs){
        this->_content= rhs._content;
        this->_size= rhs._size;
    }
    return *this;
};

std::string Req_File::getContent() const{
    return _content;
};

size_t Req_File::getSize() const{
    return _size;
};

std::string Req_File::getStatus() const{
    return _status;
};
