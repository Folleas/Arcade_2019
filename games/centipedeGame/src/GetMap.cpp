/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GetMap
*/

#include "../include/GameCore.hpp"

void Centipede::printMap(void)
{
    for(int i=0; i < _map.size(); i++)
        std::cout << _map.at(i) << '\n';
}

bool Centipede::initMap(void)
{
    std::string line;
    std::ifstream myfile("map2");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            _map.push_back(line);
        }
    myfile.close();
    }
    else {
        std::cout << "Unable to open file";
        exit (84);
    }
    return true;
}

void Centipede::initObstacles(void)
{
    for(int i=0; i < _map.size(); i++) {
        for (int j=0; _map.at(i)[j]; j++)
            if (_map.at(i)[j] == 'x') {
                this->_obstacles.push_back((struct Obstacles){j, i, 5});
            }
    }
//    for (int i=0; i < _obstacles.size(); i++)
//        std::cout << "la val de x: " << _obstacles.at(i)._x << " la val de y: " << _obstacles.at(i)._y << " la val de life: " << _obstacles.at(i)._life << std::endl;
    return ;
}