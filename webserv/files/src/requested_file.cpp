/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requested_file.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/12/29 22:48:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <requested_file.hpp>
#include <iostream>

Req_File::Req_File(void){
    return ;
};

Req_File::Req_File(Config const & conf, Req_Parser const & parser){

    bool is_allowed = false;

    if (conf.getAllowedMethods().size()){
        for (size_t i = 0; i < conf.getAllowedMethods().size(); i++){
            if (parser.getMethod() == conf.getAllowedMethods().at(i)){
                is_allowed = true;
                break ;
            }
        }
    }
    else
        is_allowed = true;

    if(is_allowed){
        if(!parser.getMethod().compare("GET"))
            isGET(conf, parser);
        else if(!parser.getMethod().compare("POST"))
            isPOST(conf, parser);
        else if(!parser.getMethod().compare("DELETE"))
            isDELETE(conf, parser);
    }
    else{
        _content = "<html><head><title>405 Not Allowed</title></head><body><h1>Not Allowed</h1><p>The request is not allowed</p></body></html>";
        _status = "405 Not Allowed";
        _size = _content.length();
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
        this->_req_file = rhs._req_file;
    }
    return *this;
};

std::string Req_File::getContent() const{
    return _content;
};
std::string Req_File::getReqFile() const{
    return _req_file;
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

void Req_File::isGET(Config const & conf, Req_Parser const & parser){
    std::ifstream   ifs;
    struct stat file_stat;
    std::string target;

    if (!conf.getRedirection().empty()){
        target = conf.getRoot() + "/" + conf.getRedirection();
        _req_file = conf.getRedirection();
    }

    else{
        if(parser.getFile() == conf.getTag() || parser.getFile() == conf.getTag() + "/"){
            target = conf.getRoot() + parser.getFile() + "/" + conf.getIndex();
            _req_file = parser.getFile() + "/" + conf.getIndex();
        }
        else{
            target = conf.getRoot() + parser.getFile();
            _req_file = parser.getFile();
        }
    }
    
    
    stat(target.c_str(), &file_stat);
    if (S_ISDIR(file_stat.st_mode)){
        if (conf.getDirIndexing()){
            DIR* dir_tar = opendir(target.c_str());
            struct dirent* dp;
            std::vector<std::string> dir_list;
            while ((dp = readdir(dir_tar))){
                std::string file_name(dp->d_name);
                dir_list.push_back(file_name);
            }
            closedir(dir_tar);
            _content = "<html><head><title>Index of " + parser.getFile() + "</title></head><body><h1>Index of " + parser.getFile() + "</h1><hr><pre>";
            for (size_t i = 0; i < dir_list.size(); i++){
                _content += "<a href=\"" + parser.getFile() + "/" + dir_list[i] + "\">" + dir_list[i] + "</a><br>";
            }
            _content +=  "</pre><hr></body></html>";
            _status = "200 OK";
        }
        else{
            _content = "<html><head><title>403 Forbidden</title></head><body><h1>Forbidden</h1><p>You do not have permission to access the requested URL. " + parser.getFile() + " is forbidden for you!</p></body></html>";
            _status = "403 Forbidden";
        }
        _size = _content.length();
    }
    else if(conf.checkCgi(target)){
        Cgi cgi(target);
        this->_content = cgi.getContent();
        this->_size = cgi.getSize();
    }
    else{
        ifs.open(target.c_str(), std::ifstream::binary);
        if (!ifs.is_open()){
            _content = "<html><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL " + parser.getFile() + " was not found on this server.</p></body></html>";
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

void Req_File::isPOST(Config const & conf, Req_Parser const & parser){
        std::ofstream ofs;
        // std::string path = conf.getRoot() + parser.getFile();

        ofs.open(conf.getUpload() + "/test.txt", std::ios::binary);
        if(!ofs.is_open()){
            _content = "{\"success\":\"false\"}";
            _status = "404 Not Found";
            _size = _content.length();
            std::cout << conf.getUpload() << std::endl;
        }
        else if(parser.getBodyLen() > conf.getMaxBody()){
            _content = "{\"success\":\"false\"}";
            _status = "431 Request Header Fields Too Large";
            _size = _content.length();
            ofs.close();
        }
        else{
            ofs.write(parser.getBody().data(), parser.getBodyLen());
            _content = "{\"success\":\"true\"}";
            if(parser.getBodyLen())
                _status = "201 Created";
            else
                _status = "204 No Content";
            _size = _content.length();
            ofs.close();
        }
};

void Req_File::isDELETE(Config const & conf, Req_Parser const & parser){
    std::string path = conf.getRoot() + parser.getFile();
    
    
    if (!remove(path.c_str())){
        _content = "{\"success\":\"true\"}";
        _status = "200 OK";
        _size = _content.length();
    }
    else{
        _content = "{\"success\":\"false\"}";
        _status = "404 Not Found";
        _size = _content.length();
    }


}