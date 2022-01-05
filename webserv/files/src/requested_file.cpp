/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requested_file.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:39:35 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/05 15:38:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <requested_file.hpp>

Req_File::Req_File(void){
    return ;
};

Req_File::Req_File(Config const & conf, Req_Parser const & parser){

    bool is_allowed = false;

    if(parser.isBad()){
        loadErrorPage("400 Bad Request", "The request is not well formatted", conf);
        return ;
    }

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
    else
        loadErrorPage("405 Not Allowed", "The request is not allowed", conf);
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
        _status = "301 Moved Permanently";
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
            for (size_t i = 0; i < dir_list.size(); ++i){
                _content += "<a href=\"" + parser.getFile() + "/" + dir_list[i] + "\">" + dir_list[i] + "</a><br>";
            }
            _content +=  "</pre><hr></body></html>";
            _status = "200 OK";
            _size = _content.length();
        }
        else
            loadErrorPage("403 Forbidden", "You do not have permission to access the requested URL. " + parser.getFile() + " is forbidden for you!", conf);
    }
    else if(conf.checkCgi(parser.getFile())){
        Cgi cgi(target, parser.getExtra());
        switch (cgi.getStatus()){
        
            case 44:
                loadErrorPage("404 Not Found", "The requested URL " + parser.getFile() + " was not found on this server.", conf);
                break;
            case 52:
                loadErrorPage("502 Bad Gateway", "The request was not completed. The server received an invalid response from the upstream server.", conf);
                break;
        
            default:
                _status = "200 OK";
                this->_content = cgi.getContent();
                this->_size = cgi.getSize();
        }
    }
    else{
        ifs.open(target.c_str(), std::ifstream::binary);
        if (!ifs.is_open())
            loadErrorPage("404 Not Found", "The requested URL " + parser.getFile() + " was not found on this server.", conf);
        else{
            if(_status.empty())
                _status = "200 OK";
            readFile(ifs);
            ifs.close();
        }
    }
};

void Req_File::isPOST(Config const & conf, Req_Parser const & parser){
    std::ofstream ofs;
    std::string path;
    if(parser.getUpFname().empty()){
        time_t now = time(NULL);
        struct tm* hu = localtime(&now);
        std::string req_time(asctime(hu));
        req_time += suffix(parser.getType());
        path = conf.getUpload() + "/" + req_time;
    }
    else
        path = conf.getUpload() + "/" + parser.getUpFname();
    
    std::ifstream ifs(path);
    
    if(ifs){
        loadErrorPage("409 Conflict", "The request could not be completed because of a conflict.", conf);
        ifs.close();
    }

    else{
        ofs.open(path , std::ios::binary);
        if(!ofs.is_open())
            loadErrorPage("500 Internal Server Error", "Internal Server Error</h1><p>The request was not completed. The server met an unexpected condition.", conf);
        else if(parser.getBodyLen() > conf.getMaxBody()){
            loadErrorPage("431 Request Header Fields Too Large", "The server will not accept the request, because the request entity is too large.", conf);
            ofs.close();
        }
        else{
            ofs.write(parser.getBody().data(), parser.getBodyLen());
             _content = "{\"success\":\"true\"}";
            // if(parser.getBodyLen())
                _status = "201 Created";
            // else
            //     _status = "204 No Content";
            _size = _content.length();
            ofs.close();
        }
    }

};

void Req_File::isDELETE(Config const & conf, Req_Parser const & parser){
    std::string path = conf.getRoot() + parser.getFile();
    
    
    if (!remove(path.c_str())){
        _status = "200 OK";
        _content = "{\"success\":\"true\"}";
        _size = _content.length();
    }
    else{
        _status = "404 Not Found";
        _content = "{\"success\":\"false\"}";
        _size = _content.length();
    }
};

int Req_File::setErrorPage(std::string const & path){
    std::ifstream ifs;
    ifs.open(path.c_str());
    if (!ifs.is_open())
        return 0;
    readFile(ifs);
    ifs.close();
    return 1;
};

void Req_File::readFile(std::ifstream & ifs){
    
    ifs.seekg(0, ifs.end);
    _size = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char buffer[_size];
    ifs.read(buffer, _size);
    _content.assign(buffer, _size);
};

std::string Req_File::suffix(std::string type) const{
    if(type.rfind("jpeg") < std::string::npos)
        return (".jpg");
    else if(type.rfind("php") < std::string::npos)
        return (".php");
    else if(type.rfind("mpeg") < std::string::npos)
        return (".mp3");
    else if(type.rfind("gif") < std::string::npos)
        return (".gif");
    else if(type.rfind("png") < std::string::npos)
        return (".png");
    else if(type.rfind("html") < std::string::npos)
        return (".html");
    else
        return ("");
};

void Req_File::loadErrorPage(std::string const & status, std::string const & msn, Config const & conf){
    _status = status;
    std::string status_name(status);
    status_name.erase(0, 4);

    switch (!conf.getErrorPages().empty()){
        case 1:
            if (setErrorPage(conf.getErrorPages() + "/" + status))
             break;
        default:
            _content = "<html><head><title>" + status + "</title></head><body><h1>"+ status_name + "</h1><p>" + msn + "</p></body></html>";
    }
     _size = _content.length();
};
