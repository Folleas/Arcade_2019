/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#include "../include/Score.hpp"

Score::Score()
{
    std::vector<char> playerNameTmp{'a', 'a', 'a'};

    this->_isRunning = true;
    this->_playerName = playerNameTmp;
    this->_cursor = 0;
    this->_direction = 1;
}

Score::~Score()
{
}

void Score::moveCursor(std::size_t direction)
{
    if (this->_cursor == 2 && direction == 1)
        this->_cursor = 0;
    else if (this->_cursor == 0 && direction == -1)
        this->_cursor = 2;
    else
        this->_cursor += direction;
}

void Score::changePlayerName(std::size_t direction)
{
    if (_playerName.at(_cursor) == 'z' && direction == 1)
        _playerName.at(_cursor) = 'a';
    else if (_playerName.at(_cursor) == 'a' && direction == -1)
        _playerName.at(_cursor) = 'z';
    else
        _playerName.at(_cursor) += direction;
}

std::string Score::getPlayerNameString()
{
    std::string playerNameString;

    playerNameString.push_back(this->_playerName.at(0));
    playerNameString.push_back(this->_playerName.at(1));
    playerNameString.push_back(this->_playerName.at(2));

    return (playerNameString);
}
