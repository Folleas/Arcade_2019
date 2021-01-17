/*
** EPITECH PROJECT, 2020
** JAM_2019
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <dlfcn.h>
#include <list>
#include <dirent.h>

#include "IDisplay.hpp"

class Button {
    public:
        Button();
        Button(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
        ~Button();

        int isClicked(std::pair<std::size_t, std::size_t> mousePosition, bool pressed, bool &pressing);
        int launchCallBack(Button &button);

        void setDisplay(bool newState);
        void setCategoryName(std::string newName);
        void setPosition(std::size_t x, std::size_t y);
        void setDimension(std::size_t width, std::size_t height);
        void setCallBack(int(*function)(Button &button));
        void setCursor(std::size_t next) {cursor = next;};
        void setNames(std::vector<std::string> newNames) {names = newNames;};
        void setColor(std::size_t r, std::size_t g, std::size_t b, std::size_t a);
        void setSelected(bool newState) {selected = newState;};
        void setHighlight(bool newState) {highlight = newState;};

        RGBA_t getColor(void) const {return _color;};
        bool getDisplay() const;
        std::string getCategoryName();
        std::size_t getCursor() const {return cursor;};
        std::vector<std::string> getNames() const {return names;};
        std::pair<std::size_t, std::size_t> getPosition(void) const;
        std::pair<std::size_t, std::size_t> getDimension(void) const;
        bool getSelected(void) const {return selected;};
        bool getHighlight(void) const {return highlight;};
    private:
        bool selected;
        bool highlight;
        bool display;

        RGBA_t _color;

        std::size_t cursor;

        std::vector<std::string> names;
        std::string categoryName = "";

        std::pair<std::size_t, std::size_t> position;
        std::pair<std::size_t, std::size_t> dimension;

        int (*callback)(Button &button);
};

#endif /* !BUTTON_HPP_ */
