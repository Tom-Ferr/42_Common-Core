#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <sstream>
# include <requested_file.hpp>


class Response
{
private:
    std::string _res;
    Response(void);
public:
    Response(Req_File const & file, std::string const & version);
    ~Response();
    Response(Response const & src);
    Response & operator=(Response const & rhs);

    std::string getResponse() const;
    size_t getSize() const;
};

#endif