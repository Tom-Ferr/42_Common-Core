/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:55:35 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/05 15:41:58 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <accept.hpp>
#include <requested_file.hpp>
#include <response.hpp>
#include <server.hpp>
#include <receive.hpp>
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

        while (1)
        {
            std::cout << "\n+++ Waiting for new connection +++\n" << std::endl;
            Poll poll(serv);
            switch (poll.status()){
                case 0:
                    std::cout << "\n* Poll Timed Out *\n" << std::endl;
                case -1:
                    continue ;
                default:
                    break;
            }
            size_t i = poll.getSelected();
            Accept  a(serv.getSock(i), serv.getBind(i));
            Receive recv(a.getSock());
            switch (recv.getStatus()){
                case 0:
                    std::cout << "\n* Connection was closed by the Client *\n" << std::endl;
                case -1:
                    close(a.getSock());
                    continue ;
                default:
                    break;
            }
            Req_Parser req(recv);
            size_t j = serv.select(i, req.getHost());
            Config conf_l = serv[i].at(j).select(req.getFile());
            Req_File file(conf_l, req);
            Response res(file, req);
            std::cout << recv.bin() << std::endl;
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
