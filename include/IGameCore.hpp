/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGameCore
*/

#ifndef IGAMECORE_HPP_
#define IGAMECORE_HPP_

#include "IDisplay.hpp"

class IGameCore {
    public:
        IGameCore() {};
        ~IGameCore() {};

        virtual void launchGame() = 0;
        virtual bool setGraphLib(const char *str) = 0;
    private:
};

typedef IGameCore *screate_t(void);

#endif /* !IGAMECORE_HPP_ */
