/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Receive.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/28 23:30:22 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <receive.hpp>

Receive::Receive(int const & sock) : _fd(sock){
    char buffer[3] = {0};
    while ((_status = recv(_fd , buffer, 1, 0))){
        _bin += buffer;
        if (_bin.rfind("\r\n\r\n") < std::string::npos)
            break ;
    }
    
};

Receive::~Receive(void){
    return ;
};

Receive::Receive(Receive const & src){
    *this = src;
};

Receive & Receive::operator=(Receive const & rhs){

    if (this != &rhs){
        this->_fd = rhs._fd;
        this->_status = rhs._status;
        this->_bin = rhs._bin;
    }
    return *this;
};

int Receive::getSock() const{
    return this->_fd;
};

int Receive::getStatus() const{
    return this->_status;
};

std::string Receive::bin() const{
    return this->_bin;
};