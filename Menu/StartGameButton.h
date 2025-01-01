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

};



#endif //STARTGAMEBUTTON_H
