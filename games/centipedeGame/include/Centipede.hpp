/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Obstacles.hpp"
#include "Character.hpp"
#include "Ennemies.hpp"
//#include "../../include/Window.hpp"
#include "Display.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int start_centipede(void);

class Centipede {
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

    protected:
        std::vector<std::string> _map;
        std::vector<Obstacles> _obstacles;
        std::vector<Ennemies> _ennemies;
        struct window_s _window;
        struct Character _character;
        struct texture_s _texture;
        struct sprite_s _sprites;
        sf::Event _event;
        sf::Clock _clock;
        sf::Clock _clockEnnemies;
        int _nbEnnemies;
    private:
};

#endif /* !CENTIPEDE_HPP_ */
