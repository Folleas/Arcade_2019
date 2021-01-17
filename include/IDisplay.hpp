/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <memory>
#include <string>

typedef struct RGBA_s {
    std::size_t r;
    std::size_t g;
    std::size_t b;
    std::size_t a;
}RGBA_t;

class IDisplay {
    public:
        IDisplay() {};
        ~IDisplay();

        virtual void initDisplay(std::size_t windowSizeX, std::size_t windowSizeY, std::string windowName) = 0;

        virtual bool eventManager(void) = 0;
        virtual bool isKeyPressed(void) = 0;
        virtual size_t eventWhichKey(void) = 0;

        virtual bool isClosed(void) = 0;
        virtual bool isMouseButtonReleased(void) = 0;
        virtual bool isMouseButtonLeft(void) = 0;
        virtual bool isMouseButtonPressed(void) = 0;

        virtual void displayWindow(void) = 0;
        virtual void clearWindow(std::size_t r, std::size_t g, std::size_t b, std::size_t a) = 0;
        virtual void closeWindow(void) = 0;

        virtual void getTicks(void) = 0;
        virtual void manageFrameRate(void) = 0;

        virtual void drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color) = 0;
        virtual void drawText(char *text, std::pair<std::size_t, std::size_t> position) = 0;

        virtual void setText(std::string str) = 0;
        virtual void setTextPosition(std::pair<std::size_t, std::size_t> position) = 0;

        virtual std::pair<std::size_t, std::size_t> getMousePosition(void) = 0;
    private:
};

typedef IDisplay *create_t(void);

#endif /* !IDISPLAY_HPP_ */
