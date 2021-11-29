#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <sstream>


class Response
{
private:
    std::string _res;
    Response(void);
public:
    Response(std::string const & target);
    ~Response();
    Response(Response const & src);
    Response & operator=(Response const & rhs);

    std::string getResponse() const;
    size_t getSize() const;
};

#endif