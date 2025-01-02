//
// Created by honza on 01.01.2025.
//

#ifndef STARTGAMEBUTTON_H
#define STARTGAMEBUTTON_H
#include "Button.h"


class StartGameButton : public Button{

    public:

    StartGameButton();
    void execute() override;
    void drawButton() override;

    void runEditPlayerSkinMenu();

private:

    void selectTypeOfPlayer(char input);

    void drawMenuWithTypeOfPlayer();
};



#endif //STARTGAMEBUTTON_H
