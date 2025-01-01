//
// Created by honza on 01.01.2025.
//

#ifndef EXITGAME_H
#define EXITGAME_H
#include "Button.h"

class ExitGame : public Button{

    public:

    ExitGame();

    void execute() override;

    void drawButton() override;

};



#endif //EXITGAME_H
