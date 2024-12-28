//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_BUTTON_H
#define DUNGEON_BUTTON_H


#include <string>

class Button {
    std::string m_label;
protected:
    Button(std::string label);
    void virtual Command();
};


#endif //DUNGEON_BUTTON_H
