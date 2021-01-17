/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Ennemies
*/

#include "../include/GameCore.hpp"

bool Centipede::touchCharacter(int i, int j)
{
    if (_ennemies.at(i)._positions.at(j).x / 40 == _character._x && _ennemies.at(i)._positions.at(j).y / 40 == _character._y)
        return (true);
    return (false);
}

bool Centipede::knowIfNextIsObstacle(int i, int j)
{
    for (int k = 0; k < _obstacles.size(); k++) {
        if (_ennemies.at(i)._positions.at(j)._direction < 0) {
            if ((_ennemies.at(i)._positions.at(j).x / 40) == _obstacles.at(k)._x && _ennemies.at(i)._positions.at(j).y / 40 == _obstacles.at(k)._y)
                return (true);
        }
        else { 
            if ((_ennemies.at(i)._positions.at(j).x / 40) + 1 == _obstacles.at(k)._x && _ennemies.at(i)._positions.at(j).y / 40 == _obstacles.at(k)._y)
                return (true);
        }

    }
    return (false);
}

void Centipede::checkMoveCentipedeObstacles(int i, int j)
{
//    std::cout << "debut move centi\n";
    checkIfEnnemieTouched(i, j);
    if (_nbEnnemies == 0) {
//        std::cout << "return empty ennemies!!!!\n";
        return;
    }
    if (_nbEnnemies - 1 < i) {
//        std::cout << "return ennemies size <!!!!\n";
        return ;
    }
    if (_ennemies.at(i)._size == 0) {
//        std::cout << "return empty position!!!!\n";
        return ;
    }
    if (_ennemies.at(i)._size - 1 < j) {
//        std::cout << "return position size < !!!!\n";
        return ;
    }
//    std::cout << "apres verif de ennemies et positions\n";
    if (_ennemies.at(i)._positions.at(j).turn > 0) {
        if (_ennemies.at(i)._positions.at(j).turn > 1)
            _ennemies.at(i)._positions.at(j).y += 10;
        else
            _ennemies.at(i)._positions.at(j).x -= _ennemies.at(i)._positions.at(j)._direction;
        _ennemies.at(i)._positions.at(j).turn = _ennemies.at(i)._positions.at(j).turn - 1;
        if (_ennemies.at(i)._positions.at(j).turn == 0)
            _ennemies.at(i)._positions.at(j)._direction = -_ennemies.at(i)._positions.at(j)._direction;
        return ;
    }
//    std::cout << "milieu check move\n";
    //si un obstacle
    if (_ennemies.at(i)._positions.at(j).x == (26 * 40) || _ennemies.at(i)._positions.at(j).x == 0)
        _ennemies.at(i)._positions.at(j).turn = 5;
    else if (knowIfNextIsObstacle(i, j) == true)
        _ennemies.at(i)._positions.at(j).turn = 5;
    else if (touchCharacter(i, j) == true || _ennemies.at(i)._positions.at(j).y >= 26 * 40)
        exit (0);
    else
        _ennemies.at(i)._positions.at(j).x += _ennemies.at(i)._positions.at(j)._direction;
//    std::cout << "fin check move centipede\n";
}

void Centipede::moveEnnemies(void)
{
    if (_clockEnnemies.getElapsedTime().asSeconds() > 0.045) {
        for (int i = 0; i < _nbEnnemies; i++) {
//            std::cout << "i: " << i << " ennemies size: " << _nbEnnemies << "\n";
            for (int j = 0; i < _nbEnnemies && j < _ennemies.at(i)._size; j++) {
//                std::cout << "j: " << j << " et position size: " << _ennemies.at(i)._size << "\n";
                checkMoveCentipedeObstacles(i, j);
            }
        }
        _clockEnnemies.restart();
    }
}

void Centipede::initEnnemies(void)
{
    std::vector<struct Position> pos;

    for (int i = 16; i > 1; i--)
        pos.push_back((struct Position){i * 40, 0, 0, 10.0});
    _ennemies.push_back((struct Ennemies){15, pos});
    _nbEnnemies = 1;
/*     for (int i = 0; i < _ennemies.size(); i++) {
    std::cout << "\n\n";
        for (int j = 0; j < _ennemies.at(i)._positions.size(); j++)
            std::cout << "la val de x: " << _ennemies.at(i)._positions.at(j).x << " la val de y: " << _ennemies.at(i)._positions.at(j).y <<  "la val de turn: " << _ennemies.at(i)._turn << std::endl;
    }
 */}