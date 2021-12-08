/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_parser.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:32:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/08 10:01:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_PARSER_HPP
# define REQUEST_PARSER_HPP

# include <string>
# include <sstream>

class Req_Parser
{
private:
    std::string _req;
    std::string _index;
    std::string _method;
    std::string _file;
    std::string _version;
    std::string _type;
    Req_Parser(void);
public:
    Req_Parser(char const *buffer, std::string const & index);
    ~Req_Parser();
    Req_Parser(Req_Parser const & src);
    Req_Parser & operator=(Req_Parser const & rhs);

    std::string getFile() const;
    std::string getVersion() const;
    std::string getType() const;
};

#endif