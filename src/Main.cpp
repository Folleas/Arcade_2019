/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Main
*/

#include "../include/Arcade.hpp"

int main(int ac, const char **av)
{
    Core save;

    if (save.checkHelp(ac, av) == true) {
        return 0;
    } else if (checkErrors(ac, av) == false)
        return 84;
    save.setSoFiles("./lib");
    if (save.setGraphLib(av[1]) == false)
        return 84;
    save.initMenu();
    save.runMenu();

    return 0;
}