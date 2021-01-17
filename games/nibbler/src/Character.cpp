/*
** EPITECH PROJECT, 2020
** nibbler
** File description:
** Character
*/

#include "../include/Character.hpp"

Nibbler::Character::Character()
{
    addCharacterPosition();
}

Nibbler::Character::~Character()
{
}

void Nibbler::Character::addCharacterPosition(void)
{
    _characterPosition.push_back(std::pair<std::size_t, std::size_t>(-1, -1));
}

bool Nibbler::Character::isCharacterDead(std::pair<std::size_t, std::size_t> mapSize) const
{
    if ((this->_characterPosition.at(0).first == 0 && this->_speed.first == -1) ||\
    (this->_characterPosition.at(0).first == mapSize.first - 1 && this->_speed.first == 1) ||\
    (this->_characterPosition.at(0).second == 0 && this->_speed.second == -1) ||\
    (this->_characterPosition.at(0).second == mapSize.second - 1 && this->_speed.second == 1))
        return (true);
    for (auto i = 1; i <= _characterPosition.size() - 1; i++) {
        if ((_characterPosition.at(0).first + 1 == _characterPosition.at(i).first && _characterPosition.at(0).second == _characterPosition.at(i).second && this->_speed.first == 1)) {
            return (true);
        }
        if ((_characterPosition.at(0).first - 1 == _characterPosition.at(i).first && _characterPosition.at(0).second == _characterPosition.at(i).second && this->_speed.first == -1)) {
            return (true);
        }
        if ((_characterPosition.at(0).second + 1 == _characterPosition.at(i).second && _characterPosition.at(0).first == _characterPosition.at(i).first && this->_speed.second == 1)) {
            return (true);
        }
        if ((_characterPosition.at(0).second - 1 == _characterPosition.at(i).second && _characterPosition.at(0).first == _characterPosition.at(i).first && this->_speed.second == -1)) {
            return (true);
        }
    }
    return (false);
}


void Nibbler::Character::manageInput(Nibbler::dir input)
{
    switch (input) {
        case dir::UP_ARROW : this->setDirection(0, -1); break;
        case dir::DOWN_ARROW : this->setDirection(0, 1); break;
        case dir::LEFT_ARROW : this->setDirection(-1, 0); break;
        case dir::RIGHT_ARROW : this->setDirection(1, 0); break;
    }
}

void Nibbler::Character::setCharacterPosition(std::size_t x, std::size_t y)
{
    _characterPosition.at(0).first = x;
    _characterPosition.at(0).second = y;
}

void Nibbler::Character::setDirection(std::size_t dirX, std::size_t dirY)
{
    this->_speed.first = dirX;
    this->_speed.second = dirY;
}

void Nibbler::Character::updateCharacterPosition()
{
    for (auto i = this->_characterPosition.size() - 1; i > 0; i--) {
        this->_characterPosition.at(i).first = this->_characterPosition.at(i - 1).first;
        this->_characterPosition.at(i).second = this->_characterPosition.at(i - 1).second;
    }
    this->_characterPosition.at(0).first += this->_speed.first;
    this->_characterPosition.at(0).second += this->_speed.second;
}