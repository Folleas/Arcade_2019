/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Event
*/

#include "../include/GameCore.hpp"

void Centipede::moveCharacter(void)
{
    if (_event.key.code == sf::Keyboard::Right)
        if (_character._x < 26) {
            _sprites.characater.move((sf::Vector2f){10.0, 0.0});
            _character._posX += 10;
            _character._x = _character._posX / 40;
        }
    if (_event.key.code == sf::Keyboard::Left)
        if (_character._x  > 0) {
            _sprites.characater.move((sf::Vector2f){-10.0, 0.0});
            _character._posX -= 10;
           _character._x = _character._posX / 40;
           if (_character._posX > 0 && _character._posX < 40)
            _character._x = 1;
        }
    if (_event.key.code == sf::Keyboard::Up)
        if (_character._y >= 20) {
            _sprites.characater.move((sf::Vector2f){0.0, -10.0});
            _character._posY -= 10;
           _character._y = _character._posY / 40;
        }
    if (_event.key.code == sf::Keyboard::Down)
        if (_character._y < 25) {
            _sprites.characater.move((sf::Vector2f){0.0, 10.0});
            _character._posY += 10;
           _character._y = _character._posY / 40;
    }
}

void Centipede::getEvent()
{
    if (_event.type == sf::Event::Closed)
        _window.window.close();
    if (_character._clock.getElapsedTime().asSeconds() > 0.03) {
        if (_event.type == sf::Event::KeyPressed) {
            moveCharacter();
        }
        _character._clock.restart();
    }
}