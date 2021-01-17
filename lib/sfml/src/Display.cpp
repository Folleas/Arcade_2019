/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Display
*/

#include "../../../include/DisplaySFML.hpp"

Display::Display()
{
    _character._fire = false;
    _character._life = true;
    _character._x = 13;
    _character._y = 22;
    _character._posX = _character._x * 40;
    _character._posY = _character._y * 40;
    _character._posFire.x = _character._posX;
    _character._posFire.y = _character._posY;
    return ;
}

Display::~Display()
{
}

bool Display::isMouseButtonReleased(void)
{
    return (_event.type == sf::Event::MouseButtonReleased);
}

bool Display::isMouseButtonLeft(void)
{
    return (_event.mouseButton.button == sf::Mouse::Left);
}

void Display::displayWindow(void)
{
    _window->display();
}

void Display::drawText(char *text, std::pair<std::size_t, std::size_t> position)
{
    this->setText(text);
    this->setTextPosition(position);
    _window->draw(this->_text);
}

bool Display::isMouseButtonPressed(void)
{
    return (_event.type == sf::Event::MouseButtonPressed);
}

void Display::setTextPosition(std::pair<std::size_t, std::size_t> position)
{
    _text.setPosition((sf::Vector2f(position.first, position.second)));
}

void Display::setText(std::string str)
{
    _text.setString(sf::String(str));
}

void Display::drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color)
{
    sf::RectangleShape rect(sf::Vector2f(dimension.first, dimension.second));
    rect.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    rect.setPosition(sf::Vector2f(position.first, position.second));
    _window->draw(rect);
}

void Display::closeWindow(void)
{
    _window->close();
}

bool Display::isClosed(void)
{
    return (_event.type == sf::Event::Closed);
}

bool Display::eventManager(void)
{
    return (_window->pollEvent(_event));
}

std::pair<std::size_t, std::size_t> Display::getMousePosition(void)
{
    sf::Vector2i mousePos2i = sf::Mouse::getPosition(*_window);
    std::pair<std::size_t, std::size_t> mousePosPair;

    mousePosPair.first = mousePos2i.x;
    mousePosPair.second = mousePos2i.y;

    return (mousePosPair);
}

void Display::clearWindow(std::size_t r, std::size_t g, std::size_t b, std::size_t a)
{
    _window->clear(sf::Color(r, g, b, a));
}

void Display::initDisplay(std::size_t windowSizeX, std::size_t windowSizeY, std::string windowName)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowSizeX, windowSizeY), windowName);
    _window->setVerticalSyncEnabled(true);
    _window->setFramerateLimit(5);
    _font.loadFromFile("res/font.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(60);
    _text.setFillColor(sf::Color(83, 92, 104, 255));
    // _text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

bool Display::isKeyPressed(void)
{
    return (this->_event.type == sf::Event::KeyPressed);
}

size_t Display::eventWhichKey(void)
{
    switch(_event.key.code) {
        case sf::Keyboard::Up : return (1);
        case sf::Keyboard::Down : return (2);
        case sf::Keyboard::Left : return (3);
        case sf::Keyboard::Right : return (4);
        case sf::Keyboard::Escape : return (5);
        default: return (-1);
    };
}

void Display::getTicks(void)
{
    return;
}

void Display::manageFrameRate(void)
{
    return;
}

extern "C" IDisplay *create(void)
{
    std::cout << "lib sfml" << std::endl;
    return (new Display());
}
