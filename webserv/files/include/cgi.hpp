/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:02:18 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/05 12:57:18 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
# define CGI_HPP

# include <sys/wait.h>
# include <unistd.h>
# include <cstdio>
# include <string>
# include <fstream>

class Cgi
{
private:
    size_t      _size;
    std::string _content;
    int _status;

    Cgi(void);
public:
    Cgi(std::string const & target, std::string const & extra);
    ~Cgi();
    Cgi(Cgi const & src);
    Cgi & operator=(Cgi const & rhs);

    size_t getSize() const;
    std::string getContent() const;
    int getStatus() const;
};


#endif