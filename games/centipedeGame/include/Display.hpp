/*
** EPITECH PROJECT, 2020
** centipedeGame
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

typedef struct RGBA_s {
    std::size_t r;
    std::size_t g;
    std::size_t b;
    std::size_t a;
}RGBA_t;

class Display {
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
        sf::RenderWindow *_window;
        sf::Font _font;
        sf::Text _text;
        sf::Event _event;
};

#endif /* !DISPLAY_HPP_ */