/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:32:40 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/08 11:26:11 by tde-cama         ###   ########.fr       */
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
    std::vector< std::vector<Config> >          _servers;
    std::vector<Socket>                         _sockets;
    std::vector<Bind>                           _binds;
    
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
    void checkSyntax(std::ifstream & ifs) const;
public:
    Server(void);
    ~Server();
    Server(Server const & src);
    Server & operator=(Server const & rhs);

     std::vector<Config> & operator[](size_t const & i);

    void start(std::string const & path);
    size_t getSize() const;
    int getSock(size_t const & i) const;
    Bind getBind(size_t const & i) const;
    size_t select(size_t const & i, std::string const & host) const;
};


#endif