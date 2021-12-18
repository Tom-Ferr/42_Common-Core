/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/18 19:39:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cgi.hpp>
#include <iostream>

Cgi::Cgi(Socket const & sock){
    sock.getSock();
    _pFile = tmpfile();
    _tmpFd = fileno(_pFile);
    int id = fork();
    if (id > 0){
        wait(NULL);
        fseek ( _pFile , 0 , SEEK_END );
        _size = ftell (_pFile);
        rewind (_pFile);
        char buffer[_size];
        fread (buffer,1,_size,_pFile);
        std::cout << buffer << std::endl;
        _content = buffer;
        fclose(_pFile);
    }
    else{
        run();
    }
};

Cgi::~Cgi(void){
    return ;
};

void Cgi::run(){
    dup2(_tmpFd, 1);
    execve("./test.script", NULL, NULL);
    exit(1);
};