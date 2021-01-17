/*
** EPITECH PROJECT, 2020
** nibbler
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "IDisplay.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
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
    protected:
        TTF_Font* _font;
        SDL_Color _color;
        SDL_Surface *_surface;
        SDL_Texture *_texture;
        std::string _text;
        SDL_Window *_window = nullptr;
        SDL_Event _event;
        SDL_Renderer *_renderer = nullptr;
        const size_t FPS = 60;
        const size_t frameDelay = 10000 / FPS;
        Uint32 frameStart;
        int frameTime;
};

#endif /* !DISPLAY_HPP_ */
