/*
** EPITECH PROJECT, 2020
** JAM_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Button.hpp"

class Menu {
    public:
        Menu();
        ~Menu();

        void runMenu(void);

        void manageMouse(std::size_t i);
        void manageEvent();
        void manageButtons();
        void checkIfPlayable();
    private:
        std::size_t buttonChoice;
        dir _lastInput = dir::UNDEFINED;
        bool _isRunning;
        std::size_t buttonVectorSize;
        std::vector<std::shared_ptr<Button>> buttons;
        std::pair<std::size_t, std::size_t> mousePosition;
        bool leftClickReleased = false;
        bool leftClickPressed = false;
};

#endif /* !MENU_HPP_ */
