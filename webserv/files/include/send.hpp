/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:17:52 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/08 11:39:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_HPP
# define SEND_HPP

# include <sys/socket.h>
# include <accept.hpp>
# include <response.hpp>
# include <requested_file.hpp>
# include <iostream>
# include <unistd.h>
# include <sys/types.h>

class Send
{
private:
    Send(void);
public:
    Send(Accept const & a, Response const & res, Req_File & file);
    ~Send(void);
    Send(Send const & src);
    Send & operator=(Send const & rhs);
};

#endif