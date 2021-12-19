/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/19 13:34:40 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cgi.hpp>

Cgi::Cgi(){
    FILE* pFile = tmpfile();
    int tmpFd = fileno(pFile);
    
    std::string first("FIRST");
    std::string s1 = "VAR1=" + first;
    std::string s2("VAR2=SECOND");
    char* env[3];
    env[0] = const_cast<char*>(s1.c_str());
    env[1] = const_cast<char*>(s2.c_str());
    env[2] = NULL;
    
    std::string s3("/usr/bin/php");
    std::string s4("./test.php");
    char* cmd[3];
    cmd[0] = const_cast<char*>(s3.c_str());
    cmd[1] = const_cast<char*>(s4.c_str());
    cmd[2] = NULL;

    int id = fork();

    if (id){
        wait(NULL);
        fseek (pFile , 0 , SEEK_END);
        _size = ftell (pFile);
        rewind (pFile);
        char buffer[_size];
        fread (buffer,1,_size,pFile);
        _content = buffer;
        fclose(pFile);
    }
    else{
        dup2(tmpFd, 1);
        execve(cmd[0], cmd, env);
        exit(1);
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