/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/09 12:20:06 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cgi.hpp>

Cgi::Cgi(std::string const & target, Req_Parser const & parser){
    FILE* pFile = tmpfile();
    int tmpFd = fileno(pFile);
    
    std::string s1 = "PATH_INFO=" + parser.getExtra();
    std::string s2 = "QUERY_STRING=" + parser.getQuery();
    std::string s3 = "HTTP_HOST=" + parser.getHost();
    char* env[4];
    env[0] = const_cast<char*>(s1.c_str());
    env[1] = const_cast<char*>(s2.c_str());
    env[2] = const_cast<char*>(s3.c_str());
    env[3] = NULL;
    
    std::string cgi;
    size_t pos = target.rfind(".");
    if (!target.compare(pos, std::string::npos, ".php"))
        cgi = "/usr/bin/php-cgi";
    else if (!target.compare(pos, std::string::npos, ".py"))
        cgi = "/usr/bin/python";
    else
        cgi = target;

    char* cmd[3];
    int i;
    cmd[0] = const_cast<char*>(cgi.c_str());
    if (cgi != target){
        cmd[1] = const_cast<char*>(target.c_str());
        i = 1;
    }
    else{
        cmd[1] = NULL;
        i = 0;
    }
    cmd[2] = NULL;

    int id = fork();

    if (id){
        wait(&_status);
        _status = WEXITSTATUS(_status);
        switch (_status)
        {
        case 44:
            break;
        
        case 52:
            break;
        
        default:
            fseek (pFile , 0 , SEEK_END);
            _size = ftell (pFile);
            rewind (pFile);
            char* buffer = new char[_size];
            fread (buffer,1,_size,pFile);
            _content.assign(buffer, _size);
            fclose(pFile);
            delete [] buffer;
        }
    }
    else{
        dup2(tmpFd, 1);
        std::ifstream ifs(cmd[i], std::ios::binary);
        if(!ifs)
            exit(44);
        ifs.close();
        execve(cmd[0], cmd, env);
        exit(52);
    }
};

Cgi::~Cgi(void){
    return ;
};

Cgi::Cgi(Cgi const & src){
    *this = src;
};

Cgi & Cgi::operator=(Cgi const & rhs){
    if (this != &rhs){
        this->_size = rhs._size;
        this->_content = rhs._content;
    }
    return *this;
};

size_t Cgi::getSize() const{
    return _size;
};

std::string Cgi::getContent() const{
    return _content;
};

int Cgi::getStatus() const{
    return _status;
};