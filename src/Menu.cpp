/*
** EPITECH PROJECT, 2020
** JAM_2019
** File description:
** Menu
*/

#include "../include/Arcade.hpp"
#include "../include/Utils.hpp"

void Core::initMenu(void)
{
    std::shared_ptr<Utils> utils = std::make_shared<Utils>();
    std::shared_ptr<Button> Play = std::make_shared<Button>(0, 450, 450, 100);
    std::shared_ptr<Button> SelectGame = std::make_shared<Button>(0, 600, 450, 100);
    std::shared_ptr<Button> GameNext = std::make_shared<Button>(650, 600, 100, 100);
    std::shared_ptr<Button> GamePrev = std::make_shared<Button>(500, 600, 100, 100);
    std::shared_ptr<Button> SelectLib = std::make_shared<Button>(0, 750, 450, 100);
    std::shared_ptr<Button> LibNext = std::make_shared<Button>(650, 750, 100, 100);
    std::shared_ptr<Button> LibPrev = std::make_shared<Button>(500, 750, 100, 100);
    std::shared_ptr<Button> Quit = std::make_shared<Button>(0, 900, 450, 100);
    std::shared_ptr<Button> Settings = std::make_shared<Button>(1820, 900, 100, 100);

    SelectGame->setNames(utils->getSoFiles("./games"));
    SelectLib->setNames(utils->getSoFiles("./lib"));
    Play->setCategoryName("Play");
    SelectGame->setCategoryName("SelectGame");
    SelectLib->setCategoryName("SelectLib");
    Quit->setCategoryName("Quit");

    Play->setCallBack(utils->runPlay);
    SelectGame->setCallBack(utils->runSelectGame);
    GameNext->setCallBack(utils->runNext);
    GamePrev->setCallBack(utils->runPrev);
    LibNext->setCallBack(utils->runNext);
    LibPrev->setCallBack(utils->runPrev);
    SelectLib->setCallBack(utils->runSelectLib);
    Quit->setCallBack(utils->runExit);
    Settings->setCallBack(utils->runSettings);

    Play->setDisplay(true);
    SelectGame->setDisplay(true);
    SelectLib->setDisplay(true);
    Quit->setDisplay(true);
    Settings->setDisplay(true);

    this->buttons.push_back(Play);
    this->buttons.push_back(SelectGame);
    this->buttons.push_back(SelectLib);
    this->buttons.push_back(Quit);
    this->buttons.push_back(GameNext);
    this->buttons.push_back(GamePrev);
    this->buttons.push_back(LibNext);
    this->buttons.push_back(LibPrev);
    this->buttons.push_back(Settings);

    this->_isRunning = true;
    this->buttonVectorSize = this->buttons.size() - 1;

    this->_lib->initDisplay(1920, 1080, "Menu");
    this->buttonChoice = 1;
}

void Core::delMenu()
{
    return;
}

size_t Core::getLinkedButton(std::size_t parsed)
{
    std::size_t chosenButton;

    if (parsed == 4 || parsed == 5)
        chosenButton = 1;
    else if (parsed == 6 || parsed == 7)
        chosenButton = 2;
    else
        chosenButton = parsed;
    return (chosenButton);
}

void Core::manageCallBack(std::size_t returnValue)
{
    switch (returnValue) {
        case 1 :
            this->buttons.at(4)->setDisplay(true);
            this->buttons.at(5)->setDisplay(true);
            this->buttons.at(6)->setDisplay(false);
            this->buttons.at(7)->setDisplay(false);
            break;
        case 2 :
            this->buttons.at(6)->setDisplay(true);
            this->buttons.at(7)->setDisplay(true);
            this->buttons.at(4)->setDisplay(false);
            this->buttons.at(5)->setDisplay(false);
            break;
        case 3 : break;
        case 4 :
            this->_lib->closeWindow();
            break;
        case 15 :
            this->setGameLib(this->buttons.at(1)->getCategoryName().c_str());
            this->_game->setGraphLib(this->buttons.at(2)->getCategoryName().c_str());
            this->_lib->closeWindow();
            this->_game->launchGame();
            break;
        default :
            this->buttons.at(4)->setDisplay(false);
            this->buttons.at(5)->setDisplay(false);
            this->buttons.at(6)->setDisplay(false);
            this->buttons.at(7)->setDisplay(false);
            break;
    }
}

void Core::manageMouseInput(std::size_t i)
{
    std::size_t linkedButton;

    switch (buttons.at(i)->isClicked(this->mousePosition, this->leftClickPressed, this->leftClickReleased)) {
        case 1 :
            linkedButton = getLinkedButton(i);
            manageCallBack(buttons.at(i)->launchCallBack(*(buttons.at(linkedButton))));
            break;
        case 2 :
            if (i != 1 && i != 4 && i != 5) {
                this->buttons.at(4)->setDisplay(false);
                this->buttons.at(5)->setDisplay(false);
            }
            if (i != 2 && i != 6 && i != 7) {
                this->buttons.at(6)->setDisplay(false);
                this->buttons.at(7)->setDisplay(false);
            }
            break;
    }
}

void Core::manageEvent()
{
    while (this->_lib->eventManager()) {
        if (this->_lib->isClosed()) {
            this->_isRunning = false;
            this->_lib->closeWindow();
            return ;
        }
        if (this->_lib->isMouseButtonPressed()) {
            if (this->_lib->isMouseButtonLeft())
                this->leftClickPressed = true;
        }
        if(this->_lib->isKeyPressed()) {
        }
        if (this->_lib->isMouseButtonReleased()) {
            if (this->_lib->isMouseButtonLeft()) {
                this->leftClickReleased = false;
            }
        }
    }
}

void Core::manageInput()
{
    for (std::size_t i = 0; i <= buttonVectorSize; i++) {
        if (buttons.at(i)->getDisplay()) {
            this->_lib->drawRect(buttons.at(i)->getPosition(), buttons.at(i)->getDimension(), buttons.at(i)->getColor());
            this->_lib->drawText((char *)buttons.at(i)->getCategoryName().c_str(), buttons.at(i)->getPosition());
            this->manageMouseInput(i);
        }
    }
}

void Core::checkIfPlayable()
{
    if (buttons.at(1)->getCursor() == (std::size_t)-1 || buttons.at(2)->getCursor() == (std::size_t)-1)
        buttons.at(0)->setColor(129, 155, 172, 255);
    else
        buttons.at(0)->setCursor(15);
}

void Core::runMenu(void)
{
    while (_isRunning) {
        this->_lib->getTicks();
        this->manageEvent();
        this->_lib->clearWindow(199, 236, 238, 255);
        this->mousePosition = this->_lib->getMousePosition();
        this->manageInput();
        this->checkIfPlayable();
        this->_lib->displayWindow();
        this->_lib->manageFrameRate();
    }
    exit (0);
}