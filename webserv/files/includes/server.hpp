/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:32:40 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/29 19:14:48 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <vector>
# include <exception>
# include <fstream>
# include <config.hpp>
# include <socket.hpp>
# include <bind.hpp>
# include <listen.hpp>

class Server
{
private:
    std::vector<Config>                         _servers;
    std::vector<Socket>                         _sockets;
    std::vector<Bind>                           _binds;
    
    Server(void);
    class FdFailedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
    class SyntaxErrorException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
public:
    Server(std::string const & path);
    ~Server();
    Server(Server const & src);
    Server & operator=(Server const & rhs);

    Config & operator[](size_t const & i);

    size_t getSize() const;
    int getSock(size_t const & i) const;
    Bind getBind(size_t const & i) const;
};


#endif