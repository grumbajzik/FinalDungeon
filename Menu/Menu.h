//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_MENU_H
#define DUNGEON_MENU_H

#include <iostream>
#include <vector>
#include "Button.h"

class Menu {
    std::vector<Button *> m_buttons;
    Button* m_chosenButton;
    int m_index;

public:

    Menu();
    void runMenu();

private:
    void selectButton(char input);
    void pressButton(char input);
    void displayMenu();
    void displeyTitleOfGame();




};


#endif //DUNGEON_MENU_H
