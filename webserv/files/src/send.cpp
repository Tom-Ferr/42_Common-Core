/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Send.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:23:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/28 23:30:22 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <send.hpp>

Send::Send(Accept const & a, Response const & res, Req_File & file){
    #ifdef _LINUX_
        int flag =  MSG_NOSIGNAL;
    #else
        int flag = 0;
    #endif

    send(a.getSock() , res.getResponse().data() , res.getSize(), 0);
    while (file.getSize() > 0) {
        ssize_t bytes = send(a.getSock(), file.getContent().data(), file.getSize(), flag);
        if(bytes == -1){
            std::cout << "¡ Not enough space at client side !" << std::endl;
            break ;
        }
        file.resize(bytes);
    }
    std::cout << "------Response sent------" << std::endl;
    close(a.getSock());
    
};

Send::~Send(void){
    return ;
};

Send::Send(Send const & src){
    *this = src;
};

Send & Send::operator=(Send const & rhs){

    if (this != &rhs){
        return *this;
    }
    return *this;
};