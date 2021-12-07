/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/07 18:56:40 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bind.hpp>

Bind::Bind(int sock_fd, struct sockaddr_in & address, Config const & conf){
    memset((char *)&address, 0, sizeof(address)); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(conf.getHost().c_str());
    address.sin_port = htons(conf.getPort());
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
        return *this;
    }
    return *this;
};

const char* Bind::FdFailedException::what() const throw(){
    return "bind() has failed";
};