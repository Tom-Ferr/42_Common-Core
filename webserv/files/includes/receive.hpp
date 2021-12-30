/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:17:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/30 18:13:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECEIVE_HPP
# define RECEIVE_HPP

# include <sys/socket.h>
# include <accept.hpp>

class Receive
{
private:
    int _fd;
    ssize_t _status;
    std::string _bin;
    Receive(void);
public:
    Receive(int const & sock);
    ~Receive(void);
    Receive(Receive const & src);
    Receive & operator=(Receive const & rhs);

    int getSock(void) const;
    int getStatus(void) const;
    std::string bin(void) const;
};

#endif