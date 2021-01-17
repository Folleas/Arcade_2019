/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "../include/Arcade.hpp"

std::list<std::string> delNotSoFiles(std::list<std::string> soList)
{
    std::list<std::string> fnl;
    std::string exten = ".so";

    for (std::string curr : soList) {
        if (curr.size() > 3) {
            if (exten.compare(curr.substr(curr.size() - 3, 3).c_str()) == 0)
                fnl.push_back(curr);
        }
    } return fnl;
}

void Core::setSoFiles(const char *path)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (path)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            this->_solist.push_back(ent->d_name);
        } closedir (dir);
    } else
        std::cerr << "Error: ";
    this->_solist = delNotSoFiles(this->_solist);
}

bool Core::checkHelp(int ac, const char **av)
{
    std::string help = "";

    if (ac == 2 && (help = av[1]).compare("-h") == 0) {
        std::cout << "USAGE:\n\t./arcade [LIB]\nOPTIONS:\n\tLIB = Graphic library to use initialy.\n";
        return true;
    } return false;
}

bool Core::setGraphLib(const char *libname)
{
    create_t *graph;

    // if (_handle)
    //     dlclose(_handle);
    std::cout << libname << std::endl;
    _handle = dlopen(libname, RTLD_LAZY);
    if (!_handle) {
        std::cout << "dlerror: " << dlerror() << std::endl;
        return false;
    }
    if (!(graph = (create_t *)dlsym(_handle, "create")))
        return false;
    _lib = graph();
    return true;
}

bool Core::setGameLib(const char *libname)
{
    screate_t *graph;
    std::string lib_n = "games/";

    lib_n.append(libname);
    lib_n.append(".so");
    // if (!_handle)
    //     dlclose(_handle);
    std::cout << lib_n << std::endl;
    _handle = dlopen(lib_n.c_str(), RTLD_LAZY);
    if (!_handle) {
        std::cout << "dlerror: " << dlerror() << std::endl;
        return false;
    }
    if (!(graph = (screate_t *)dlsym(_handle, "create")))
        return false;
    _game = graph();
    return true;
}