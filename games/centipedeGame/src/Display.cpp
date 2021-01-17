/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Display
*/

#include "../include/GameCore.hpp"

//Display Ennemies
void Centipede::displayEnnemies(void)
{
    if (_nbEnnemies == 0)
            initEnnemies();
    for (int i = 0; i < _nbEnnemies; i++) {
        for (int j = 0; _nbEnnemies > i && j < _ennemies.at(i)._size; j++) {
            if (j != 0)
                _sprites.ennemie.setTextureRect(sf::IntRect{0, 18, 16, 8});
            else 
                _sprites.ennemie.setTextureRect(sf::IntRect{0, 0, 16, 8});
            moveEnnemies();
            if (_nbEnnemies > i  && _ennemies.at(i)._size > j)
                _sprites.ennemie.setPosition(_ennemies.at(i)._positions.at(j).x, _ennemies.at(i)._positions.at(j).y);
            _window.window.draw(_sprites.ennemie);
        }
    }
}

//Display for shot
void Centipede::displayShot(void)
{
    if (_character._clockFire.getElapsedTime().asSeconds() > 0.00001) {
        _sprites.shot.move((sf::Vector2f){0.0, -0.3334 * 4});
        _character._posFire.y = _character._posFire.y - (0.3334 * 4);
        _character._clockFire.restart();
        _window.window.draw(_sprites.shot);
        checkColision();
    }
}

//Display for character
void Centipede::displayCharacter(void)
{
    _window.window.draw(_sprites.characater);
}

//Display for obstacles
void Centipede::updateSpriteObstacle(int life)
{
    if (life == 5)
        _sprites.obstacles.setTextureRect((sf::Rect<int>) {0, 0, 8, 8});
    if (life == 4)
        _sprites.obstacles.setTextureRect((sf::Rect<int>) {9, 0, 8, 8});
    if (life == 3)
        _sprites.obstacles.setTextureRect((sf::Rect<int>) {18, 0, 8, 8});
    if (life == 2)
        _sprites.obstacles.setTextureRect((sf::Rect<int>) {27, 0, 8, 8});
    if (life == 1)
        _sprites.obstacles.setTextureRect((sf::Rect<int>) {36, 0, 8, 8});
}

void Centipede::displayObstacles(void)
{
    for (int i = 0; i < _obstacles.size(); i++) {
        if (_obstacles.at(i)._life > 0) {
            updateSpriteObstacle(_obstacles.at(i)._life);
            _sprites.obstacles.setPosition((sf::Vector2f){(float)_obstacles.at(i)._x * 40, (float)_obstacles.at(i)._y * 40});
            _window.window.draw(_sprites.obstacles);
        }
    }
    return ;
}