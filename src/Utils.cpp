/*
** EPITECH PROJECT, 2020
** JAM_2019
** File description:
** Utils
*/

#include "../include/Utils.hpp"

std::vector<std::string> Utils::delNotSoFiles(std::vector<std::string> soList)
{
    std::vector<std::string> fnl;
    std::string exten = ".so";

    for (std::string curr : soList) {
        if (curr.size() > 3) {
            if (exten.compare(curr.substr(curr.size() - 3, 3).c_str()) == 0) {
                curr.resize(curr.size() - 3);
                fnl.push_back(curr);
            }
        }
    } return fnl;
}

std::vector<std::string> Utils::getSoFiles(const char *path)
{
    std::vector<std::string> soFiles;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (path)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            soFiles.push_back(ent->d_name);
        } closedir (dir);
    } else {
        std::cerr << "Error: ";
    } soFiles = delNotSoFiles(soFiles);
    return soFiles;
}

int Utils::runPlay(Button &button)
{
    if (button.getCursor() == 15) {
    return (15);
    }
    return (11);
}

int Utils::runSettings(Button &button)
{
    (void)button;
    std::cout << "Settings" << std::endl;
    return (10);
}

int Utils::runExit(Button &button)
{
    (void)button;
    std::cout << "Exit" << std::endl;
    return (4);
}

int Utils::runSelectGame(Button &button)
{
    (void)button;
    std::cout << "Game\n";
    return (1);
}

int Utils::runSelectLib(Button &button)
{
    (void)button;
    std::cout << "Lib\n";
    return (2);
}

int Utils::runNext(Button &button)
{
    std::size_t cursor = button.getCursor();

    if (cursor == (std::size_t)-1)
        cursor = 0;
    std::cout << cursor << std::endl;
    if (cursor < button.getNames().size() - 1) {
        cursor++;
    }
    else
        cursor = 0;
    button.setCursor(cursor);
    button.setCategoryName(button.getNames().at(cursor));
    return (3);
}

int Utils::runPrev(Button &button)
{
    std::size_t cursor = button.getCursor();

    if (cursor == (std::size_t)-1)
        cursor = 0;
    if (cursor > 0) {
        cursor--;
    }
    else
        cursor = button.getNames().size() - 1;
    button.setCursor(cursor);
    button.setCategoryName(button.getNames().at(cursor));
    return (3);
}
