/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Character
*/

#include "../include/GameCore.hpp"

void Centipede::initCharacter(void)
{
    _character._fire = false;
    _character._life = true;
    _character._x = 13;
    _character._y = 22;
    _character._posX = _character._x * 40;
    _character._posY = _character._y * 40;
    _character._posFire.x = _character._posX;
    _character._posFire.y = _character._posY;
    return ;
}