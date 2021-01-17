/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Error
*/

#include "../include/Arcade.hpp"

bool checkErrors(int ac, const char **av)
{
    void *handle = nullptr;
    // void (*hello)(void);

    if (ac != 2 || !(handle = dlopen(av[1], RTLD_LAZY))) {
        std::cerr << "TEST\t" << dlerror() << std::endl;
        return false;
    }
    // *(void **)(&hello) = dlsym(handle, "hello");
    // if (dlerror()) {
    //     std::cout << dlerror() << std::endl;
    //     return false;
    // } (*hello)();
    dlclose(handle);
    return true;
}