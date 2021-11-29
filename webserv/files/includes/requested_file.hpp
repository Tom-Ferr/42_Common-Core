#ifndef REQUESTED_FILE_HPP
# define REQUESTED_FILE_HPP

# include <string>
# include <fstream>


class Req_File
{
private:
    std::string _content;
    size_t _size;
    Req_File(void);
public:
    Req_File(std::string const & target);
    ~Req_File();
    Req_File(Req_File const & src);
    Req_File & operator=(Req_File const & rhs);

    std::string getContent() const;
    size_t getSize() const;
};

#endif