/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Graphics.hpp>

struct window_s
{
    bool status;
    int x;
    int y;
    float scale;
    sf::RenderWindow window;
};

struct texture_s
{
    sf::Texture character;
    sf::Texture ennemie;
    sf::Texture shot;
    sf::Texture obstacles;
    sf::Texture alphaNum;
};

struct sprite_s
{
    sf::Sprite characater;
    sf::Sprite ennemie;
    sf::Sprite shot;
    sf::Sprite obstacles;
    sf::Sprite alphaNum;
};

struct Character {
    int _x;
    int _y;
    int _posX;
    int _posY;
    bool _life;
    bool _fire;
    sf::Clock _clock;
    sf::Clock _clockFire;
    sf::Vector2f _posFire;
};

#endif /* !DISPLAY_HPP_ */
