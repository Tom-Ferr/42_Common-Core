/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:17:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/07 18:57:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIND_HPP
# define BIND_HPP

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <exception>
# include <cstring>
# include <config.hpp>

class Bind
{
private:

    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
    Bind(void);
public:
    Bind(int sock_fd, struct sockaddr_in & address, Config const & conf);
    ~Bind(void);
    Bind(Bind const & src);
    Bind & operator=(Bind const & rhs);
};

#endif