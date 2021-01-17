/*
** EPITECH PROJECT, 2020
** nibbler
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <vector>

namespace Nibbler {
    enum dir {
        UNDEFINED = -1,
        ESC = 0,
        UP_ARROW = 1,
        DOWN_ARROW = 2,
        LEFT_ARROW = 3,
        RIGHT_ARROW = 4,
        SPACE_BAR = 5
    };
}

namespace Nibbler {
    class Character {
        public:
            Character();
            ~Character();

            void updateCharacterPosition();
            void manageInput(Nibbler::dir input);
            void incAppleCount() {appleCount += 1;};
            bool isCharacterDead(std::pair<std::size_t, std::size_t> mapSize) const;
            void addCharacterPosition(void);

            std::vector<std::pair<std::size_t, std::size_t>> getCharacterPosition() const {return _characterPosition;};
            std::size_t getAppleCount() const {return (appleCount);};

            void setDirection(std::size_t dirX, std::size_t dirY);
            void setCharacterPosition(std::size_t x, std::size_t y);
        private:
            std::vector<std::pair<std::size_t, std::size_t>> _characterPosition;
            std::pair<std::size_t, std::size_t> _speed;
            std::size_t appleCount;
    };
}

#endif /* !CHARACTER_HPP_ */