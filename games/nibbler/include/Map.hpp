/*
** EPITECH PROJECT, 2020
** nibbler
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <memory>
#include "Character.hpp"

namespace Nibbler {
    class Map {
        public:
            Map();
            ~Map();

            void generateApple(void);
            void isAppleEaten(std::shared_ptr<Nibbler::Character> character);
            std::shared_ptr<Nibbler::Character> getCharacter() const {return _character;};
            std::pair<std::size_t, std::size_t> getMapSize(void) const {return _mapSize;};
            std::pair<std::size_t, std::size_t> getActualMapSize(void) const {return _actualMapSize;};
            std::pair<std::size_t, std::size_t> getApplePosition(void) const {return _applePosition;};
            std::size_t getCellSize(void) const {return _cellSize;};
            std::pair<std::size_t, std::size_t> getDisplayPosition(void) const {return (_displayPosition);};

            void setIsApple(bool newState) {isApple = newState;};
            void setMapSize(std::size_t sizeX, std::size_t sizeY);
            void setActualMapSize(std::size_t sizeX, std::size_t sizeY);
            void setApplePosition(std::size_t sizeX, std::size_t sizeY);
        protected:
            std::shared_ptr<Nibbler::Character> _character;
            std::pair<std::size_t, std::size_t> _mapSize;
            std::pair<std::size_t, std::size_t> _actualMapSize;
            std::pair<std::size_t, std::size_t> _applePosition;
            std::pair<std::size_t, std::size_t> _displayPosition;
            std::size_t _cellSize;
            bool isApple;
    };
};

#endif /* !MAP_HPP_ */