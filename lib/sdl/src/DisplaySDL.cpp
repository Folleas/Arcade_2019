/*
** EPITECH PROJECT, 2020
** nibbler
** File description:
** Display
*/

#include "../../../include/DisplaySDL.hpp"

Display::Display()
{
}

Display::~Display()
{
}

void Display::initDisplay(std::size_t windowSizeX, std::size_t windowSizeY, std::string windowName)
{
    if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else {
        _window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, 0);
        if(!_window) {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        if (!_renderer)
            std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    TTF_Init();
    _font = TTF_OpenFont("res/font.ttf", 128);
    _color = {200, 200, 200, 255};
}

void Display::clearWindow(std::size_t r, std::size_t g, std::size_t b, std::size_t a)
{
    SDL_RenderClear(_renderer);
}

void Display::getTicks(void)
{
    frameStart = SDL_GetTicks();
}

void Display::displayWindow(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(_renderer);
}

void Display::manageFrameRate(void)
{
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
}

void Display::closeWindow(void)
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

size_t Display::eventWhichKey(void)
{
    switch(_event.key.keysym.sym) {
        case SDLK_UP: return (1);
        case SDLK_DOWN: return (2);
        case SDLK_LEFT: return (3);
        case SDLK_RIGHT: return (4);
        case SDLK_SPACE: return (5);
        default: return (-1);
    }
}

bool Display::isKeyPressed(void)
{
    if (_event.type == SDL_KEYDOWN)
        return (1);
    return (0);
}

bool Display::eventManager(void)
{
    if (SDL_PollEvent(&(this->_event)) == 0)
        return (false);
    return (true);
}

void Display::drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color)
{
    SDL_Rect rect;
    rect.w = dimension.first;
    rect.h = dimension.second;
    rect.x = position.first;
    rect.y = position.second;
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &rect);
}

bool Display::isClosed(void)
{
    return (_event.type == SDL_QUIT);
}

bool Display::isMouseButtonReleased(void)
{
    return (_event.button.state == SDL_RELEASED && _event.type == SDL_MOUSEBUTTONUP);
}

bool Display::isMouseButtonLeft(void)
{
    return (_event.button.button == SDL_BUTTON_LEFT);
}

bool Display::isMouseButtonPressed(void)
{
    return (_event.type == SDL_MOUSEBUTTONDOWN);
}

void Display::drawText(char *text, std::pair<std::size_t, std::size_t> position)
{
    _surface = TTF_RenderText_Solid(_font, text, _color);
    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    SDL_Rect messageRect;
    messageRect.x = position.first;
    messageRect.y = position.second;
    messageRect.w = 100;
    messageRect.h = 100;
    SDL_RenderCopy(_renderer, _texture, NULL, &messageRect);
}

void Display::setText(std::string str)
{
    std::cout << "setTextSDL\n";
    return;
}

void Display::setTextPosition(std::pair<std::size_t, std::size_t> position)
{
    return;
}

std::pair<std::size_t, std::size_t> Display::getMousePosition(void)
{
    std::pair<std::size_t, std::size_t> mousePosition;

    SDL_GetMouseState((int*)(&mousePosition.first), (int *)(&mousePosition.second));
    return (mousePosition);
}

extern "C" IDisplay *create(void)
{
    std::cout << "lib sdl" << std::endl;
    return (new Display());
}