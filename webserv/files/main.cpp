/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:55:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/29 15:18:09 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <socket.hpp>
#include <bind.hpp>
#include <listen.hpp>
#include <accept.hpp>
#include <req_parser.hpp>
#include <requested_file.hpp>
#include <iostream>
#include <unistd.h>

#define PORT 8080

int main()
{

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    std::string site_Dir = "site";
    
    std::string res = "HTTP/1.1 200 OK\nContent-Type: text/html;charset=UTF-8\nContent-Length: 2431\n\n";
    
    try
    {
        Socket  s;
        Bind    b(s.getSock(), address, PORT);
        Listen  l(s.getSock());
        while (1)
        {
            std::string c_res = res;
            std::cout << "\n+++ Waiting for new connection +++\n" << std::endl;;

            Accept  a(s.getSock(), address, addrlen);

            char buffer[30000] = {0};
            recv( a.getSock() , buffer, 30000, 0);
            Req_Parser req(buffer);
            Req_File file(site_Dir + req.getFile());
            c_res += file.getContent();
            std::cout << buffer << std::endl;
            send(a.getSock() , c_res.c_str() , c_res.length(), 0);
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
