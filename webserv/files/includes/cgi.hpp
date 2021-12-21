/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:02:18 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/21 11:57:48 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
# define CGI_HPP

# include <sys/wait.h>
# include <unistd.h>
# include <cstdio>
# include <string>

class Cgi
{
private:
    size_t      _size;
    std::string _content;

    Cgi(void);
public:
    Cgi(std::string const & target);
    ~Cgi();
    Cgi(Cgi const & src);
    Cgi & operator=(Cgi const & rhs);

    size_t getSize() const;
    std::string getContent() const;
};


#endif