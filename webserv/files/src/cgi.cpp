/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/08 14:16:58 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cgi.hpp>

Cgi::Cgi(Socket const & socket){
    int id = fork();
    if (id)
        wait(NULL);
    else
        run();
};

Cgi::~Cgi(void){
    return ;
};

void Cgi::run(){
    dup2(socket.getSock(), 0);
    execve("/bin/php", cmd, env);
};