//
// Created by honza on 01.01.2025.
//

#ifndef STARTGAMEBUTTON_H
#define STARTGAMEBUTTON_H
#include "Button.h"
#include <vector>
#include "../Options.h"

#include "../Player/Player.h"

class StartGameButton : public Button{

    std::vector<std::string> m_typeOfPlayer;
    int m_index;

    public:

    StartGameButton();
    void execute() override;
    void drawButton() override;
    void runStartGameMenu();
    PlayerType getTypeOfPlayer();

private:

    void selectTypeOfPlayer(char input);

    void drawMenuWithTypeOfPlayer();
};



#endif //STARTGAMEBUTTON_H
