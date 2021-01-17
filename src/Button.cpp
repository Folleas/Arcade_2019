/*
** EPITECH PROJECT, 2020
** JAM_2019
** File description:
** Button
*/

#include "../include/Button.hpp"

Button::Button()
{

}

Button::Button(std::size_t x, std::size_t y, std::size_t width, std::size_t height)
{
    this->cursor = -1;
    this->position.first = x;
    this->position.second = y;
    this->dimension.first = width;
    this->dimension.second = height;
    this->display = false;
    this->selected = false;
    this->highlight = false;
}

Button::~Button()
{
}

int Button::isClicked(std::pair<std::size_t, std::size_t> mousePosition, bool pressed, bool &pressing)
{
    if (mousePosition.first >= this->position.first && mousePosition.first <=  this->position.first + this->dimension.first && mousePosition.second >= this->position.second && mousePosition.second <= this->position.second + this->dimension.second) {
        this->setColor(149, 175, 192, 200);
        if (pressed && pressing == false) {
            pressing = true;
            this->setColor(149, 175, 192, 255);
            return (1);
        }
        else {
            return (2);
        }
    }
    this->setColor(149, 175, 192, 128);
    return (0);
}

void Button::setColor(std::size_t r, std::size_t g, std::size_t b, std::size_t a)
{
    this->_color.r = r;
    this->_color.g = g;
    this->_color.b = b;
    this->_color.a = a;
}

void Button::setDisplay(bool newState)
{
    this->display = newState;
}

int Button::launchCallBack(Button &button)
{
    return (this->callback(button));
}

void Button::setCallBack(int(*function)(Button &button))
{
    this->callback = function;
}

void Button::setCategoryName(std::string newName)
{
    this->categoryName = newName;
}

void Button::setPosition(std::size_t x, std::size_t y)
{
    this->position.first = x;
    this->position.second = y;
}

void Button::setDimension(std::size_t width, std::size_t height)
{
    this->dimension.first = width;
    this->dimension.second = height;
}

std::string Button::getCategoryName()
{
    return (this->categoryName);
}

std::pair<std::size_t, std::size_t> Button::getPosition(void) const
{
    return (this->position);
}

std::pair<std::size_t, std::size_t> Button::getDimension(void) const
{
    return (this->dimension);
}

bool Button::getDisplay() const
{
    return (this->display);
}