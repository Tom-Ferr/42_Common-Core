/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   req_parser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:32:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/11/29 13:19:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQ_PARSER_HPP
# define REQ_PARSER_HPP

# include <string>
# include <sstream>

class Req_Parser
{
private:
    std::string _req;
    Req_Parser(void);
public:
    Req_Parser(char const *buffer);
    ~Req_Parser();
    Req_Parser(Req_Parser const & src);
    Req_Parser & operator=(Req_Parser const & rhs);

    std::string getFile() const;
};

#endif