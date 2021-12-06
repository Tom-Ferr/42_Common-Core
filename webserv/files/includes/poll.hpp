/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:09:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/04 18:46:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLL_HPP
# define POLL_HPP
# include <sys/select.h>
# include <socket.hpp>
# include <accept.hpp>

class Poll
{
private:
    char buffer[30000] = {0};
    Poll(void);
    Accept a;
public:
    Poll(Socket const & sock);
    ~Poll();
    Poll(Poll const & src);
    Poll & operator=(Poll const & rhs);
};

#endif