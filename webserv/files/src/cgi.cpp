/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:27 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/05 13:08:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cgi.hpp>
#include <iostream>

Cgi::Cgi(std::string const & target, std::string const & extra){
    FILE* pFile = tmpfile();
    int tmpFd = fileno(pFile);
    
    std::string s1 = "PATH_INFO=" + extra;
    char* env[2];
    env[0] = const_cast<char*>(s1.c_str());
    env[1] = NULL;
    
    std::string cgi;
    size_t pos = target.rfind(".");
    if (!target.compare(pos, std::string::npos, ".php"))
        cgi = "/usr/bin/php";
    else if (!target.compare(pos, std::string::npos, ".py"))
        cgi = "/usr/local/bin/python3";
    else
        cgi = target;

    char* cmd[3];
    cmd[0] = const_cast<char*>(cgi.c_str());
    if (cgi != target)
        cmd[1] = const_cast<char*>(target.c_str());
    else
        cmd[1] = NULL;
    cmd[2] = NULL;

    int id = fork();

    if (id){
        wait(&_status);
        _status = WEXITSTATUS(_status);
        std::cout << _status << std::endl;
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
            char buffer[_size];
            fread (buffer,1,_size,pFile);
            _content.assign(buffer, _size);
            fclose(pFile);
        }
    }
    else{
        dup2(tmpFd, 1);
        std::ifstream ifs(cmd[1]);
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