#ifndef REQUESTED_FILE_HPP
# define REQUESTED_FILE_HPP

# include <string>
# include <fstream>
# include <cstdio>
# include <vector>
# include <request_parser.hpp>
# include <config.hpp>
# include <sys/stat.h>
# include <dirent.h>


class Req_File
{
private:
    std::string _content;
    size_t _size;
    std::string _status;
    Req_File(void);
public:
    Req_File(Config const & conf, Req_Parser const & parser);
    ~Req_File();
    Req_File(Req_File const & src);
    Req_File & operator=(Req_File const & rhs);

    std::string getContent() const;
    size_t getSize() const;
    std::string getStatus() const;
    void resize(size_t const & len);
};

#endif