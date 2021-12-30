/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/29 22:51:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bind.hpp>

Bind::Bind(int sock_fd, Config const & conf){
    _addrlen = sizeof(_address);
    memset((char *)&_address, 0, sizeof(_address)); 
    _address.sin_family = AF_INET; 
    _address.sin_addr.s_addr = inet_addr(conf.getHost().c_str());
    _address.sin_port = htons(conf.getPort());
    if (bind(sock_fd, (struct sockaddr *)&_address, sizeof(_address)) < 0) { 
         throw Bind::FdFailedException();
    }
};

Bind::~Bind(void){
    return ;
};

Bind::Bind(Bind const & src){
    *this = src;
};

Bind & Bind::operator=(Bind const & rhs){
    if (this != &rhs){
        this->_address = rhs._address;
        this->_addrlen = rhs._addrlen;
    }
    return *this;
};

const char* Bind::FdFailedException::what() const throw(){
    return "bind() has failed";
};

struct sockaddr* Bind::getSockAddress() const{
    return (struct sockaddr *)&_address;
};

socklen_t* Bind::getSockLen() const{
    return (socklen_t*)&_addrlen;
};