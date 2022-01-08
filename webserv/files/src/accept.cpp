/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/07 21:35:16 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <accept.hpp>

Accept::Accept(int const & sock, Bind const & bind){
    if ((_fd = accept(sock, bind.getSockAddress(), bind.getSockLen())) < 0){
        throw Accept::FdFailedException();
    }
    fcntl(_fd, F_SETFL, O_NONBLOCK);
    #ifndef  _LINUX_
        int set = 1;
        setsockopt(_fd, SOL_SOCKET, SO_NOSIGPIPE, (void *)&set, sizeof(int));
    #endif
};

Accept::~Accept(void){
    return ;
};

Accept::Accept(Accept const & src){
    *this = src;
};

Accept & Accept::operator=(Accept const & rhs){

    if (this != &rhs){
        this->_fd = rhs._fd;
    }
    
    return *this;
};

const char* Accept::FdFailedException::what() const throw(){
    return "accept() has failed";
};

int Accept::getSock() const{
    return this->_fd;
};