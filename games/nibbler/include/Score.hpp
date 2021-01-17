/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <vector>
#include <string>
#include <fstream>

class Score {
    public:
        Score();
        ~Score();

        void changePlayerName(std::size_t direction);
        void moveCursor(std::size_t direction);

        std::string getPlayerNameString();
    protected:
        std::size_t _direction;
        std::size_t _cursor;
        std::vector<char> _playerName;
        bool _isRunning;
};

#endif /* !SCORE_HPP_ */