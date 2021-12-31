/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:51:05 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/30 20:40:38 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <poll.hpp>

Poll::Poll(Server const & serv){
    struct pollfd pfds[serv.getSize()];
    for (size_t i = 0; i < serv.getSize(); ++i){
        pfds[i].fd = serv.getSock(i);
        pfds[i].events = POLLIN;
    }
    poll(pfds, serv.getSize(), 50000);
    for (size_t i = 0; i < serv.getSize(); ++i){
        if (pfds[i].revents == POLLIN){
            _selected = i;
            break ;
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
        this->_selected = rhs._selected;
    }
    return *this;
};

size_t Poll::getSelected() const{
    return _selected;
};