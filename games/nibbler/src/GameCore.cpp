/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameCore
*/

#include "../include/GameCore.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <filesystem>
#include <fstream>

Nibbler::GameCore::GameCore()
{
    std::shared_ptr<Button> firstLetter = std::make_shared<Button>(405, 600, 300, 300);
    std::shared_ptr<Button> secondLetter = std::make_shared<Button>(810, 600, 300, 300);
    std::shared_ptr<Button> thirdLetter = std::make_shared<Button>(1215, 600, 300, 300);
    std::shared_ptr<Button> Done = std::make_shared<Button>(1550, 800, 200, 100);

    firstLetter->setCategoryName("a");
    secondLetter->setCategoryName("a");
    thirdLetter->setCategoryName("a");
    Done->setCategoryName("Engrave");

    firstLetter->setCallBack(this->runElse);
    secondLetter->setCallBack(this->runElse);
    thirdLetter->setCallBack(this->runElse);
    Done->setCallBack(this->runDone);

    firstLetter->setDisplay(true);
    secondLetter->setDisplay(true);
    thirdLetter->setDisplay(true);
    Done->setDisplay(true);

    this->buttons.push_back(firstLetter);
    this->buttons.push_back(secondLetter);
    this->buttons.push_back(thirdLetter);
    this->buttons.push_back(Done);
}

Nibbler::GameCore::~GameCore()
{
}

int Nibbler::GameCore::runElse(Button &button)
{
    return (0);
}

int Nibbler::GameCore::runDone(Button &button)
{
    return (1);
}

void Nibbler::GameCore::manageEvent()
{
    while(_display->eventManager()) {
        if(_display->isKeyPressed()) {
            switch(_display->eventWhichKey()) {
                case 1: this->_lastInput = dir::UP_ARROW; break;
                case 2: this->_lastInput = dir::DOWN_ARROW; break;
                case 3: this->_lastInput = dir::LEFT_ARROW; break;
                case 4: this->_lastInput = dir::RIGHT_ARROW; break;
                case 5: _character->addCharacterPosition(); break;
                default: break;
            }
        }
        if (_display->isClosed()) {
            _display->closeWindow();
        }
        if (this->_display->isMouseButtonPressed()) {
            if (this->_display->isMouseButtonLeft())
                this->leftClickPressed = true;
        }
        if (this->_display->isMouseButtonReleased()) {
            if (this->_display->isMouseButtonLeft()) {
                this->leftClickReleased = false;
            }
        }
    }
}

void Nibbler::GameCore::manageMap()
{
    _display->drawRect(this->getDisplayPosition(), this->getActualMapSize(), (RGBA_t){255, 0, 0, 255});
    this->generateApple();
    std::pair<std::size_t, std::size_t> applePosition;
    applePosition.first = this->getDisplayPosition().first + ((this->getApplePosition().first * this->getCellSize()));
    applePosition.second = this->getDisplayPosition().second + ((this->getApplePosition().second * this->getCellSize()));
    _display->drawRect(applePosition, std::pair<std::size_t, std::size_t>{this->getCellSize(), this->getCellSize()}, (RGBA_t){0, 255, 0, 255});
}

void Nibbler::GameCore::manageCharacter()
{
    _character->manageInput(this->_lastInput);
    _character->updateCharacterPosition();
    for (auto i = 0; i <= _character->getCharacterPosition().size() - 1; i++) {
        std::pair<std::size_t, std::size_t> position;
        position.first = this->getDisplayPosition().first + ((_character->getCharacterPosition().at(i).first * this->getCellSize()));
        position.second = this->getDisplayPosition().second + ((_character->getCharacterPosition().at(i).second * this->getCellSize()));
        _display->drawRect(position, std::pair<std::size_t, std::size_t>{this->getCellSize(), this->getCellSize()}, (RGBA_t){0, 0, 255, 255});
    }
    this->isAppleEaten(_character);
    if (_character->isCharacterDead(this->getMapSize()))
        _scoreScreen = true;
}

void Nibbler::GameCore::initGame(void)
{
    this->_windowSize.first = 1920;
    this->_windowSize.second = 1080;
    _character = this->getCharacter();
    _isRunning = true;
    this->_mapSize.first = 10;
    this->_mapSize.second = 10;
    this->_cellSize = 50;
    this->setActualMapSize(getMapSize().first * this->getCellSize(), getMapSize().second * this->getCellSize());
    _display->initDisplay(this->_windowSize.first, this->_windowSize.second, "Nibbler");
    std::srand(std::time(nullptr));
    this->isApple = false;

    this->_displayPosition.first = (1920 / 2) - ((this->getMapSize().first * this->getCellSize()) / 2);
    this->_displayPosition.second = (1080 / 2) - ((this->getMapSize().second * this->getCellSize()) / 2);

    _character = std::make_unique<Nibbler::Character>();
    _character->setCharacterPosition(_mapSize.first / 2, _mapSize.second / 2);
}

void Nibbler::GameCore::manageButtons()
{
    if (this->_lastInput == dir::UP_ARROW)
        this->changePlayerName(1);
    if (this->_lastInput == dir::DOWN_ARROW)
        this->changePlayerName(-1);
    if (this->_lastInput == dir::LEFT_ARROW)
        this->moveCursor(-1);
    if (this->_lastInput == dir::RIGHT_ARROW)
        this->moveCursor(1);
    std::pair<std::size_t, std::size_t> mousePosition = _display->getMousePosition();
    if (this->_lastInput == dir::UNDEFINED && mousePosition.first >= this->buttons.at(3)->getPosition().first && mousePosition.first <=  this->buttons.at(3)->getPosition().first + this->buttons.at(3)->getDimension().first && mousePosition.second >= this->buttons.at(3)->getPosition().second && mousePosition.second <= this->buttons.at(3)->getPosition().second + this->buttons.at(3)->getDimension().second) {
        _cursor = 3;
    }
    switch (this->_cursor) {
        case 0 : mousePosition = this->buttons.at(0)->getPosition(); this->leftClickPressed = true; break;
        case 1 : mousePosition = this->buttons.at(1)->getPosition(); this->leftClickPressed = true; break;
        case 2 : mousePosition = this->buttons.at(2)->getPosition(); this->leftClickPressed = true; break;
        default : break;
    }
    for (std::size_t i = 0; i <= buttons.size() - 1; i++) {
        if (i != 3) {
            std::string tmp;
            tmp.push_back(this->_playerName.at(i));
            this->buttons.at(i)->setCategoryName(tmp);
        }
        this->_display->drawRect(buttons.at(i)->getPosition(), buttons.at(i)->getDimension(), buttons.at(i)->getColor());
        this->_display->drawText((char *)buttons.at(i)->getCategoryName().c_str(), buttons.at(i)->getPosition());
        switch (buttons.at(i)->isClicked(mousePosition, this->leftClickPressed, this->leftClickReleased)) {
            case 1 :
                switch (buttons.at(i)->launchCallBack(*(buttons.at(i)))) {
                    case 1 : this->writeScore(); _display->closeWindow(); this->_isRunning = false; break;
                    default : break;
                }
                break;
            default :
                break;
        }
    }
    this->_lastInput = dir::UNDEFINED;
}

void Nibbler::GameCore::writeScore()
{
    std::ifstream fileStream("res/score.arc");
    std::ofstream outStream("res/tmp_score.arc");
    std::string tmp;

    if (fileStream && outStream) {
        while (fileStream >> tmp) {
            if (tmp.compare(0, 3, this->getPlayerNameString().c_str()) == 0)
                outStream << this->getPlayerNameString() << "-" << "NIB:" << this->_character->getAppleCount() << "\n";
            else
                outStream << tmp << "\n";
        } rename("res/tmp_score.arc", "res/score.arc");
    } else
        std::cout << "Coudn't open/write score.arc" << std::endl;
}

        // fileStream << this->getPlayerNameString() << "\t" << "NIB:" << this->_character->getAppleCount() << "\n";

void Nibbler::GameCore::manageScoreScreen(void)
{
    manageButtons();
}

void Nibbler::GameCore::gameLoop()
{
    _display->getTicks();
    this->manageEvent();
    if (_scoreScreen) {
        _display->clearWindow(199, 236, 238, 255);
        this->manageScoreScreen();
    }
    else {
        _display->clearWindow(0, 0, 0, 0);
        this->manageMap();
        this->manageCharacter();
    }
    _display->displayWindow();
    _display->manageFrameRate();
}

void Nibbler::GameCore::launchGame()
{
    initGame();
    while (_isRunning) {
        gameLoop();
    }
    exit(0);
}

bool Nibbler::GameCore::setGraphLib(const char *libname)
{
    create_t *graph;
    std::string lib_n = "lib/";

    lib_n.append(libname);
    lib_n.append(".so");
    // if (!_handle)
    //     dlclose(_handle);
    std::cout << lib_n << std::endl;
    _handle = dlopen(lib_n.c_str(), RTLD_LAZY);
    if (!_handle) {
        std::cout << "dlerror: " << dlerror() << std::endl;
        return false;
    }
    if (!(graph = (create_t *)dlsym(_handle, "create")))
        return false;
    _display = graph();
    return true;
}

extern "C" IGameCore *create(void)
{
    std::cout << "lib nibbler" << std::endl;
    return (new Nibbler::GameCore());
}