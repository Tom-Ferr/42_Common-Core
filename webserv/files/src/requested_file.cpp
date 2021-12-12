/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requested_file.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/12 14:53:15 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <requested_file.hpp>

Req_File::Req_File(void){
    return ;
};

Req_File::Req_File(std::string const & target){
    std::ifstream   ifs;
    struct stat file_stat;

    stat(target.c_str(), &file_stat);
    if (S_ISDIR(file_stat.st_mode)){
        DIR* dir_tar = opendir(target.c_str());
        struct dirent* dp;
        std::vector<std::string> dir_list;
        while ((dp = readdir(dir_tar))){
            std::string file_name(dp->d_name);
            dir_list.push_back(file_name);
        }
        closedir(dir_tar);
        _content = "<html><head><title>Index of " + target + "</title></head><body><h1>Index of " + target + "</h1><hr><pre>";
        for (size_t i = 0; i < dir_list.size(); i++){
            _content += "<a href=\"" + dir_list[i] + "\">" + dir_list[i] + "</a><br>";
        }
        _content +=  "</pre><hr></body></html>";
        _status = "200 OK";
        _size = _content.length();
    }

    else{
        ifs.open(target.c_str(), std::ifstream::binary);
        if (!ifs.is_open()){
            _content = "<html><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL " + target + " was not found on this server.</p></body></html>";
            _status = "404 Not Found";
            _size = _content.length();
        }
        else{

            _status = "200 OK";
            ifs.seekg(0, ifs.end);
            _size = ifs.tellg();
            ifs.seekg(0, ifs.beg);
            char buffer[_size];
            ifs.read(buffer, _size);
            _content.assign(buffer, _size);
            ifs.close();
        }
    }
    
};

Req_File::~Req_File(void){
    return ;
};

Req_File::Req_File(Req_File const & src){
    *this = src;
};

Req_File & Req_File::operator=(Req_File const & rhs){
    if (this != &rhs){
        this->_content= rhs._content;
        this->_size = rhs._size;
        this->_status = rhs._status;
    }
    return *this;
};

std::string Req_File::getContent() const{
    return _content;
};

size_t Req_File::getSize() const{
    return _size;
};

std::string Req_File::getStatus() const{
    return _status;
};
void Req_File::resize(size_t const & len) {
    _content.erase(0, len);
    _size -= len;
};
