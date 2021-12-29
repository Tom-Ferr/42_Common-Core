/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poll.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:42:11 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/28 22:52:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POLL_HPP
# define POLL_HPP

# include <poll.h>
# include <accept.hpp>
# include <server.hpp>

class Poll
{
private:
    size_t  _selected;
public:
    Poll(Server const & serv, struct pollfd pfds[]);
    ~Poll();
    Poll(Poll const & src);
    Poll & operator=(Poll const & rhs);

    size_t getSelected() const;
};

#endif