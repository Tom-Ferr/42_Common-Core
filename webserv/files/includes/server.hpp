/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:32:40 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/28 15:55:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <vector>
# include <exception>
# include <fstream>
# include <config.hpp>

class Server
{
private:
    std::vector<Config> _servers;
    
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

    Config & operator[](size_t i);

    size_t getSize() const;
};


#endif