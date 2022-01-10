/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:46:55 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/09 13:45:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <socket.hpp>

Socket::Socket(void){
    if ((_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        throw Socket::FdFailedException();
    }
};

Socket::~Socket(void){
    return ;
};

Socket::Socket(Socket const & src){
    *this = src;
};

Socket & Socket::operator=(Socket const & rhs){
    if (this != &rhs){
        this->_fd = rhs._fd;
    }
    return *this;
};

const char* Socket::FdFailedException::what() const throw(){
    return "socket() has failed";
};

int Socket::getSock() const{
    return this->_fd;
};