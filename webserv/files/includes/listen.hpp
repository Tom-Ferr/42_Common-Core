/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:17:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/28 18:34:21 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Listen_HPP
# define Listen_HPP

# include <sys/socket.h>
// # include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <exception>
# include <cstring>

class Listen
{
private:
    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
    Listen(void);
public:
    Listen(int sock_fd);
    ~Listen(void);
    Listen(Listen const & src);
    Listen & operator=(Listen const & rhs);
};

#endif