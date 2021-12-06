/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:55:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/06 17:34:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <socket.hpp>
#include <bind.hpp>
#include <listen.hpp>
#include <accept.hpp>
#include <request_parser.hpp>
#include <requested_file.hpp>
#include <response.hpp>
#include <iostream>
#include <unistd.h>
#include <poll.h>

#define PORT 8080

int main()
{

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    std::string site_Dir = "site";
    struct pollfd pfds[1];
    
    try
    {
        Socket  s;
        Bind    b(s.getSock(), address, PORT);
        Listen  l(s.getSock());

        while (1)
        {
            std::cout << "\n+++ Waiting for new connection +++\n" << std::endl;
            Accept  a(s.getSock(), address, addrlen);
            pfds[0].fd = a.getSock();
            pfds[0].events = POLLIN;
            poll(pfds, 2, 20000);
            char buffer[30000] = {0};
            recv( a.getSock() , buffer, 30000, 0);
            Req_Parser req(buffer);
            Req_File file(site_Dir + req.getFile());
            Response res(file);
            std::cout << buffer << std::endl;
            send(a.getSock() , res.getResponse().c_str() , res.getSize(), 0);
            std::cout << "------Hello message sent------" << std::endl;
            close(a.getSock());
        }
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
