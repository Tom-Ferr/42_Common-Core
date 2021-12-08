#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <sstream>
# include <requested_file.hpp>
# include <request_parser.hpp>


class Response
{
private:
    std::string _res;
    std::string _len;
    std::string _type;
    Response(void);
public:
    Response(Req_File const & file, Req_Parser const & req);
    ~Response();
    Response(Response const & src);
    Response & operator=(Response const & rhs);

    std::string getResponse() const;
    size_t getSize() const;
};

#endif