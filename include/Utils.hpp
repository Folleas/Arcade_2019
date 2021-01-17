/*
** EPITECH PROJECT, 2020
** JAM_2019
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>

#include "Button.hpp"

class Utils {
    public:
        static int runPlay(Button &button);
        static int runSettings(Button &button);
        static int runExit(Button &button);
        static int runSelectGame(Button &button);
        static int runSelectLib(Button &button);
        static int runNext(Button &button);
        static int runPrev(Button &button);

        std::vector<std::string> getSoFiles(const char *path);
        std::vector<std::string> delNotSoFiles(std::vector<std::string> soList);
};

#endif /* !UTILS_HPP_ */
