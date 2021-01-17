/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

struct Character {
    int _x;
    int _y;
    int _posX;
    int _posY;
    bool _life;
    bool _fire;
    sf::Clock _clock;
    sf::Clock _clockFire;
    sf::Vector2f _posFire;
};

#endif /* !CHARACTER_HPP_ */
