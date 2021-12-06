/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poll.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:46:55 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/02 13:43:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <poll.hpp>

Poll::Poll(Socket const & sock, struct sockaddr_in const & address, int const & addrlen){
    fd_set read_fd, write_fd;

    FD_ZERO(&read_fd);
    FD_SET(sock.getSock(), &read_fd);
    FD_ZERO(&write_fd);
    FD_SET(sock.getSock(), &write_fd);
    while(1){
        select(1, &read_fd, &write_fd, NULL, NULL);
        if (FD_ISSET(sock.getSock(), &read_fd)){
           Accept  acc(sock.getSock(), address, addrlen);
           a = acc;
        }
    }
};

Poll::~Poll(void){
    return ;
};

Poll::Poll(Poll const & src){
    *this = src;
};

Poll & Poll::operator=(Poll const & rhs){
    if (this != &rhs){

    }
    return *this;
};

// const char* Poll::FdFailedException::what() const throw(){
//     return "select() has failed";
// };
