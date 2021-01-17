/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameCore
*/

#ifndef GAMECORE_HPP_
#define GAMECORE_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <dlfcn.h>

#include "Obstacles.hpp"
//#include "Character.hpp"
#include "Ennemies.hpp"
//#include "Window.hpp"
//#include "Display.hpp"
#include "../../../include/IGameCore.hpp"
#include "../../../include/IDisplay.hpp"

class Centipede : public IGameCore {
    public:
        Centipede();
        ~Centipede();
        bool initMap(void);
        void printMap(void);
        void initObstacles(void);
        void initCharacter(void);
        void initEnnemies(void);
        void start(void);
        void displayObstacles(void);
        void initTexture(void);
        void initSprites(void);
        void initWindow(void);
        void getEvent();
        void updateSpriteObstacle(int life);
        void displayCharacter(void);
        void moveCharacter(void);
        void displayShot(void);
        void checkColision(void);
        void displayEnnemies(void);
        void moveEnnemies(void);
        void directionForEnnemies(int i, int j);
        void checkMoveCentipedeObstacles(int i, int j);
        bool knowIfNextIsObstacle(int i, int j);
        bool touchCharacter(int i, int j);
        void checkIfEnnemieTouched(int i, int j);

        void launchGame(void);
        bool setGraphLib(const char *str);
    private:
        std::vector<std::string> _map;
        std::vector<Obstacles> _obstacles;
        std::vector<Ennemies> _ennemies;
//        struct Character _character;
        int _nbEnnemies;

        create_t *_graph;
        void *_handle;
        IDisplay *_display;
};

#endif /* !GAMECORE_HPP_ */