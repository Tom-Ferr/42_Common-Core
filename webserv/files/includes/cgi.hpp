/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:02:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/18 18:58:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
# define CGI_HPP

# include <socket.hpp>
# include <sys/wait.h>
# include <unistd.h>
# include <cstdio>
# include <string>

class Cgi
{
private:
    size_t      _size;
    std::string _content;
    FILE*       _pFile;
    int         _tmpFd;
    int         _stdout;

    Cgi(void);
    void run();
public:
    Cgi(Socket const & sock);
    ~Cgi();
};


#endif