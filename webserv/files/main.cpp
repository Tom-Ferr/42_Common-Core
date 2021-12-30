/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:55:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/30 16:56:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <accept.hpp>
#include <requested_file.hpp>
#include <response.hpp>
#include <server.hpp>
#include <poll.hpp>
#include <iostream>
#include <unistd.h>

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
    
    try
    {
        Server serv(config_path);
        struct pollfd pfds[serv.getSize()];

        while (1)
        {
            std::cout << "\n+++ Waiting for new connection +++\n" << std::endl;
            Poll poll(serv, pfds);
            size_t i = poll.getSelected();
            Accept  a(serv.getSock(i), serv.getBind(i));
            char buffer[3] = {0};
            std::string bin;
            while (recv(a.getSock() , buffer, 1, 0)){
                bin += buffer;
                if (bin.rfind("\r\n\r\n") < std::string::npos)
                    break ;
            }
            Req_Parser req(bin.c_str(), a.getSock());
            size_t j = serv.select(i, req.getHost());
            Config conf_l = serv[i].at(j).select(req.getFile());
            Req_File file(conf_l, req);
            Response res(file, req);
            std::cout << bin.c_str() << std::endl;
            send(a.getSock() , res.getResponse().data() , res.getSize(), 0);
            while (file.getSize() > 0) {
                size_t bytes = send(a.getSock(), file.getContent().data(), file.getSize(), 0);
                file.resize(bytes);
            }
            std::cout << "------Response sent------" << std::endl;
            close(a.getSock());
        }
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return 2;
    }
    return 0;
}
