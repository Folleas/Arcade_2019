/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "IGameCore.hpp"
#include "IDisplay.hpp"
#include "Button.hpp"

#include <filesystem>
#include <string>
#include <iostream>
#include <memory>
#include <dlfcn.h>
#include <list>
#include <dirent.h>

bool checkErrors(int, const char **);
std::list<std::string> getSoFiles(const char *);

enum dir {
    UNDEFINED = -1,
    ESC = 0,
    UP_ARROW = 1,
    DOWN_ARROW = 2,
    LEFT_ARROW = 3,
    RIGHT_ARROW = 4,
    SPACE_BAR = 5
};

class Core
{
    public:
        Core() {};
        ~Core() {};

        void initMenu(void);
        void delMenu(void);
        void runMenu(void);
        void manageMouseInput(std::size_t i);
        void manageEvent();
        void manageInput();
        void manageCallBack(std::size_t returnValue);
        void checkIfPlayable();
        std::size_t getLinkedButton(std::size_t parsed);

        bool setGameLib(const char *);
        bool setGraphLib(const char *);

        void setSoFiles(const char *);
        std::list<std::string> getSoFiles(void) const {return _solist;}
        bool checkHelp(int ac, const char **av);
        IDisplay *getLib(void) const {return _lib;}
    private:
        std::list<std::string> _solist;
        void *_handle;
        IGameCore *_game;
        IDisplay *_lib;

        std::size_t buttonChoice;
        dir _lastInput = dir::UNDEFINED;
        bool _isRunning;
        std::size_t buttonVectorSize;
        std::vector<std::shared_ptr<Button>> buttons;
        std::pair<std::size_t, std::size_t> mousePosition;
        bool leftClickReleased = false;
        bool leftClickPressed = false;
};

#endif /* !ARCADE_HPP_ */
