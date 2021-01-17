/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "../include/GameCore.hpp"

Centipede::Centipede(void)
{
    return ;
}

Centipede::~Centipede(void)
{
    return ;
}

bool Centipede::setGraphLib(const char *libname)
{
    create_t *graph;
    std::string lib_n = "lib/";

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
    if (!(graph = (create_t *)dlsym(_handle, "create")))
        return false;
    _display = graph();
    return true;
}

void launchGame(void)
{
    Centipede cent;
//    cent.initWindow();
//    cent.initMap();
//    cent.initObstacles();
//    cent.initCharacter();
//    cent.initEnnemies();
//    cent.initTexture();
//    cent.initSprites();
//    cent.start();
    return ;
}

extern "C" IGameCore *create(void) {
    return (new Centipede());
}

//void Centipede::start(void)
//{
//    while (_window.window.isOpen())
//    {
//        while (_window.window.pollEvent(_event))
//            getEvent();
//        _window.window.clear();
//        displayObstacles();
//        displayCharacter();
//        displayEnnemies();
//        displayShot();
//        _window.window.display();
//        _clock.restart();
//    }
//    return ;
//}

/* int main(void)
{
    start_centipede();
    return (0);
} */