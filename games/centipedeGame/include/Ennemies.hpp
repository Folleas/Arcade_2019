/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Ennemies
*/

#ifndef ENNEMIES_HPP_
#define ENNEMIES_HPP_

#include <vector>

struct Position
{
    int x;
    int y;
    int turn;
    float _direction;
};

struct Ennemies {
    int _size;
    std::vector<struct Position> _positions;
};

#endif /* !ENNEMIES_HPP_ */
