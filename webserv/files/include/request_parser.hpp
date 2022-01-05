/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_parser.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:32:35 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/04 23:40:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_PARSER_HPP
# define REQUEST_PARSER_HPP

# include <string>
# include <sstream>
# include <sys/socket.h>
# include <receive.hpp>

class Req_Parser
{
private:
    std::string _req;
    std::string _method;
    std::string _file;
    std::string _extra;
    std::string _version;
    std::string _type;
    std::string _body;
    std::string _s_blen;
    std::string _host;
    std::string _trans_enc;
    std::string _boundary;
    std::string _up_fname;
    int         _sock;
    size_t      _body_len;
    bool      _bad;
    Req_Parser(void);
    void readBody(size_t const & len);
    void readChunk(std::string & bin);
    void unchunk();
public:
    Req_Parser(Receive const & recv);
    ~Req_Parser();
    Req_Parser(Req_Parser const & src);
    Req_Parser & operator=(Req_Parser const & rhs);

    std::string getFile() const;
    std::string getExtra() const;
    std::string getVersion() const;
    std::string getType() const;
    std::string getMethod() const;
    std::string getBody() const;
    std::string getHost() const;
    std::string getUpFname() const;
    size_t getBodyLen() const;
    bool isBad() const;
    void parseBody();
};

#endif
