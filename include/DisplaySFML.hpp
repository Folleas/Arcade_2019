/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "IDisplay.hpp"
#include "Window.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <iostream>
#include <string>

class Display : public IDisplay
{
    public:
        Display();
        ~Display();

        void initDisplay(std::size_t windowSizeX, std::size_t windowSizeY, std::string windowName);

        bool eventManager(void);
        bool isKeyPressed(void);
        size_t eventWhichKey(void);

        bool isClosed(void);
        bool isMouseButtonReleased(void);
        bool isMouseButtonLeft(void);
        bool isMouseButtonPressed(void);

        void displayWindow(void);
        void clearWindow(std::size_t r, std::size_t g, std::size_t b, std::size_t a);
        void closeWindow(void);

        void getTicks(void);
        void manageFrameRate(void);

        void drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color);
        void drawText(char *text, std::pair<std::size_t, std::size_t> position);

        void setText(std::string str);
        void setTextPosition(std::pair<std::size_t, std::size_t> position);

        std::pair<std::size_t, std::size_t> getMousePosition(void);
    private:
        std::shared_ptr<sf::RenderWindow> _window;
        sf::Font _font;
        sf::Text _text;
        sf::Event _event;

        struct window_s _win;
        struct texture_s _texture;
        struct sprite_s _sprites;
        sf::Clock _clock;
        sf::Clock _clockEnnemies;
        struct Character _character;
};

#endif /* !DISPLAY_HPP_ */