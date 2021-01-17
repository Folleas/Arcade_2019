/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** LoadSprites
*/

#include "../include/GameCore.hpp"

void Centipede::initWindow(void)
{
    _window.status = true;
    _window.x = 1080;
    _window.y = 1080;
    _window.scale = 1;
    _window.window.create(sf::VideoMode(_window.x, _window.y), "Centipede!");
}

void Centipede::initTexture(void)
{
    if (!_texture.character.loadFromFile("./resources/Character.png")) {
        std::cerr << "Unable to load file\n";
        exit (0);
    }
    _sprites.characater.setPosition((sf::Vector2f){(float)(_character._x * 40), (float)(_character._y * 40)});
    if (!_texture.ennemie.loadFromFile("./resources/Ennemie.png")) {
        std::cerr << "Unable to load file\n";
        exit (0);
    }
    if (!_texture.shot.loadFromFile("./resources/Fire.png")) {
        std::cerr << "Unable to load file\n";
        exit (0);
    }
    _sprites.shot.setPosition(_character._posFire);
    if (!_texture.obstacles.loadFromFile("./resources/Block.png")) {
        std::cerr << "Unable to load file\n";
        exit (0);
    }
    if (!_texture.alphaNum.loadFromFile("./resources/AlphaNum.png")) {
        std::cerr << "Unable to load file\n";
        exit (0);
    }
}

void Centipede::initSprites(void)
{
    _sprites.characater.setTexture(_texture.character);
//    _sprites.characater.setScale({10.0, 10.0});
    _sprites.ennemie.setTexture(_texture.ennemie);
//    _sprites.ennemie.setScale({10.0, 10.0});
    _sprites.shot.setTexture(_texture.shot);
//    _sprites.shot.setScale({10.0, 10.0});
    _sprites.obstacles.setTexture(_texture.obstacles);
//    _sprites.obstacles.setScale({10.0, 10.0});
    _sprites.alphaNum.setTexture(_texture.alphaNum);
//    _sprites.alphaNum.setScale({10.0, 10.0});
}