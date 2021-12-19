/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:55:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/18 21:26:15 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <socket.hpp>
#include <bind.hpp>
#include <listen.hpp>
#include <accept.hpp>
#include <request_parser.hpp>
#include <requested_file.hpp>
#include <response.hpp>
#include <config.hpp>
#include <cgi.hpp>
#include <iostream>
#include <unistd.h>
#include <poll.h>

int main(int argc, char* argv[])
{

    if(argc > 2){
        std::cout << "Too many arguments" << std::endl;
        return 1;
    }
    std::string config_path;
    if(argc > 1){
        config_path = argv[1];
    }
    else
        config_path = "default.conf";
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    struct pollfd pfds[1];
    
    try
    {
        Config conf(config_path);
        Socket  s;
        Bind    b(s.getSock(), address, conf);
        Listen  l(s.getSock());
        Cgi cgi;

        while (1)
        {
            std::cout << "\n+++ Waiting for new connection +++\n" << std::endl;
            Accept  a(s.getSock(), address, addrlen);
            pfds[0].fd = a.getSock();
            pfds[0].events = POLLIN;
            poll(pfds, 1, 50000);
            char buffer[30000] = {0};
            recv(a.getSock() , buffer, 30000, 0);
            Req_Parser req(buffer);
            Config conf_l = conf.select(req.getFile());
            Req_File file(conf_l, req);
            Response res(file, req);
            std::cout << buffer << std::endl;
            send(a.getSock() , res.getResponse().data() , res.getSize(), 0);
            while (file.getSize() > 0) {
                size_t bytes = send(a.getSock(), file.getContent().data(), file.getSize(), 0);
                file.resize(bytes);
            }
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
