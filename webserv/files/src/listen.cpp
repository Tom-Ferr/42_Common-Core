/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/06 15:32:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listen.hpp>

Listen::Listen(int sock_fd){
    if (listen(sock_fd, 10) < 0) { 
        throw Listen::FdFailedException();
    }
};

Listen::~Listen(void){
    return ;
};

Listen::Listen(Listen const & src){
    *this = src;
};

Listen & Listen::operator=(Listen const & rhs){
    if (this != &rhs)
        return *this;
    return *this;
};

const char* Listen::FdFailedException::what() const throw(){
    return "listen() has failed";
};