/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameCore
*/

#ifndef GAMECORE_HPP_
#define GAMECORE_HPP_

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "./Map.hpp"
#include "./Score.hpp"

#include <dlfcn.h>

#include "../../../include/IGameCore.hpp"
#include "../../../include/IDisplay.hpp"
#include "../../../include/Button.hpp"

namespace Nibbler {
    class GameCore : public IGameCore, Map, Score {
        public:
            GameCore();
            ~GameCore();

            void initGame(void);
            void gameLoop(void);
            void displayMap(void);
            void displayApple(void);
            void displayCharacter(std::shared_ptr<Nibbler::Character> character);
            void launchGame(void);
            void manageEvent(void);
            void manageMap(void);
            void manageCharacter(void);
            void manageScoreScreen(void);
            void manageButtons();

            static int runDone(Button &button);
            static int runElse(Button &button);

            void writeScore();

            bool setGraphLib(const char *str);
        private:
            create_t *_graph;
            void *_handle;
            IDisplay *_display;

            std::vector<std::shared_ptr<Button>> buttons;
            std::shared_ptr<Nibbler::Character> _character;
            std::pair<std::size_t, std::size_t> _windowSize;
            dir _lastInput = dir::UNDEFINED;
            bool _isRunning;
            bool _scoreScreen;
            bool leftClickReleased = false;
            bool leftClickPressed = false;
    };
};

#endif /* !GAMECORE_HPP_ */