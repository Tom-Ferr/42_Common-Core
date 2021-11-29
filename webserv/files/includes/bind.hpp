/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:17:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/28 18:34:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIND_HPP
# define BIND_HPP

# include <sys/socket.h>
// # include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <exception>
# include <cstring>

class Bind
{
private:
    int _port;

    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
    Bind(void);
public:
    Bind(int sock_fd, struct sockaddr_in & address, int const & port);
    ~Bind(void);
    Bind(Bind const & src);
    Bind & operator=(Bind const & rhs);
};

#endif