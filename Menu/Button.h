//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_BUTTON_H
#define DUNGEON_BUTTON_H


#include <iostream>

class Button {

protected:

    std::string m_label;

    public:

    Button();
    virtual void execute() = 0;
    virtual void drawButton() = 0;

};


#endif //DUNGEON_BUTTON_H
