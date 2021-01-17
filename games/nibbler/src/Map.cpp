/*
** EPITECH PROJECT, 2020
** Test
** File description:
** Map
*/

#include "../include/Map.hpp"
#include <ctime>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Nibbler::Map::Map()
{

}

Nibbler::Map::~Map()
{
}

void Nibbler::Map::generateApple(void)
{
    if (!this->isApple) {
        this->_applePosition.first = std::rand() % this->_mapSize.first;
        this->_applePosition.second = std::rand() % this->_mapSize.second;
        this->isApple = true;
    }
}

void Nibbler::Map::isAppleEaten(std::shared_ptr<Nibbler::Character> character)
{
    if (character->getCharacterPosition().at(0).first == this->getApplePosition().first && character->getCharacterPosition().at(0).second == this->getApplePosition().second) {
        this->setIsApple(false);
        character->incAppleCount();
        character->addCharacterPosition();
    }
}

void Nibbler::Map::setMapSize(std::size_t sizeX, std::size_t sizeY)
{
    std::pair<std::size_t, std::size_t> newMapSize;

    newMapSize.first = sizeX;
    newMapSize.second = sizeY;
    this->_mapSize = newMapSize;
}

void Nibbler::Map::setActualMapSize(std::size_t sizeX, std::size_t sizeY)
{
    std::pair<std::size_t, std::size_t> newMapSize;

    newMapSize.first = sizeX;
    newMapSize.second = sizeY;
    this->_actualMapSize = newMapSize;
}
