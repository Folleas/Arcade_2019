/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Colision
*/

#include "../include/GameCore.hpp"

void Centipede::checkIfEnnemieTouched(int i, int j)
{
    struct Ennemies tmp;
    std::vector<Position> save;

    if (_ennemies.at(i)._positions.at(j).x / 40 == (int)_character._posFire.x / 40 && _ennemies.at(i)._positions.at(j).y / 40 == (int)_character._posFire.y / 40 ) {
        _obstacles.push_back((struct Obstacles){(int)_character._posFire.x / 40, (int)_character._posFire.y / 40, 5});
        for (int k = j + 1; k < _ennemies.at(i)._size; k++)
            save.push_back(_ennemies.at(i)._positions.at(k));
        if (j != 0 && j != _ennemies.at(i)._size - 1) {
            tmp._positions = save;
            tmp._size = tmp._positions.size();
            _ennemies.at(i)._size = _ennemies.at(i)._size - tmp._size - 1;
            _ennemies.push_back(tmp);
            _nbEnnemies = _nbEnnemies + 1;
            for (std::vector<Position>::iterator it = _ennemies.at(i)._positions.end() - 1; it != _ennemies.at(i)._positions.begin() + j - 1; it--)
                it = _ennemies.at(i)._positions.erase(it);
        }
        else {
            _ennemies.at(i)._positions.erase(_ennemies.at(i)._positions.begin() + j);
            _ennemies.at(i)._size = _ennemies.at(i)._size - 1;
        }
        _character._posFire.x = _character._posX;
        _character._posFire.y = _character._posY;
        if (_ennemies.at(i)._positions.size() == 0) {
            _ennemies.erase(_ennemies.begin() + i);
            _nbEnnemies = _nbEnnemies - 1;
        }
    }
}

void Centipede::checkColision(void)
{
    if (_character._posFire.y <= 1) {
        _character._posFire.x = _character._posX;
        _character._posFire.y = _character._posY;
        _sprites.shot.setPosition(_character._posFire);
    }
    for (int i = 0; i < _obstacles.size(); i++) {
        if (_obstacles.at(i)._x  == (int)(_character._posFire.x / 40) && _obstacles.at(i)._y == (int)(_character._posFire.y / 40)) {
            _sprites.shot.setPosition((sf::Vector2f){(float)_character._posX, (float)_character._posY});
            _character._posFire = (sf::Vector2f){(float)_character._posX, (float)_character._posY};
            _obstacles.at(i)._life = _obstacles.at(i)._life - 1;
            if (_obstacles.at(i)._life == 0)
                _obstacles.erase(_obstacles.begin()+i);
        }
    }
}