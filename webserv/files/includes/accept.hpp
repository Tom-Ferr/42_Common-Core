/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:17:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/04 20:43:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Accept_HPP
# define Accept_HPP

# include <sys/socket.h>
// # include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <exception>
# include <cstring>
# include <fcntl.h>

class Accept
{
private:
    int _fd;
    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
public:
    Accept(void);
    Accept(int sock_fd, struct sockaddr_in const & address, int const & addrlen);
    ~Accept(void);
    Accept(Accept const & src);
    Accept & operator=(Accept const & rhs);

    int getSock(void) const;
};

#endif