/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:20:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/28 18:34:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <sys/socket.h>
// # include <sys/types.h>
# include <exception>

class Socket
{
private:
    int _fd;

    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

public:
    Socket(void);
    ~Socket();
    Socket(Socket const & src);
    Socket & operator=(Socket const & rhs);

    int getSock(void) const;
};

#endif