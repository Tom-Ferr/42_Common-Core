/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/28 18:26:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bind.hpp>

Bind::Bind(int sock_fd, struct sockaddr_in & address, int const & port) : _port(port){
    memset((char *)&address, 0, sizeof(address)); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = htonl(INADDR_ANY); 
    address.sin_port = htons(_port);
    if (bind(sock_fd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
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
        this->_port = rhs._port;
    }
    return *this;
};

const char* Bind::FdFailedException::what() const throw(){
    return "bind() has failed";
};