//
// Created by honza on 03.01.2025.
//

#ifndef HOWTOPLAYBUTTON_H
#define HOWTOPLAYBUTTON_H
#include "Button.h"


class HowToPlayButton : public Button{

    public:

    HowToPlayButton();

    void execute() override;

    void drawButton() override;

    void runHowToPlayMenu();

private:

    void drawMenu();
};



#endif //HOWTOPLAYBUTTON_H
