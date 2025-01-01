//
// Created by Admin on 27.12.2024.
//

#include "Menu.h"

#include "EditPlayerSkin.h"
#include "ExitGame.h"
#include "StartGameButton.h"

Menu::Menu() {
    m_buttons.push_back(new StartGameButton());
    m_buttons.push_back(new EditPlayerSkin());
    m_buttons.push_back(new ExitGame());
    m_index = 0;
    m_chosenButton = m_buttons.at(m_index);
}

void Menu::displayMenu() {
    system("cls");
    displeyTitleOfGame();
    for (int i = 0; i < m_buttons.size(); i++) {
        if (i == m_index) {
            std::cout << "> ";
        }else {
            std::cout << "  ";
        }
        m_buttons.at(i)->drawButton();
    }
}

void Menu::selectButton(char input) {
    input = static_cast<int>(input);
    switch (input) {
        case 72: { //up
            if (m_index > 0) {
                m_index--;
            }
            break;
        }
        case 80: {  // down
            if (m_index < m_buttons.size() - 1) {
                m_index++;
            }
            break;
        }
        default:
            break;
    }
    m_chosenButton = m_buttons.at(m_index);
}

void Menu::pressButton(char input) {
    if (input == '\r') {
        m_chosenButton->execute();
    }
}

void Menu::displeyTitleOfGame() {
    std::cout << "=========================" << std::endl;
    std::cout << "      DUNGEON ZOO      " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << std::endl;
}


void Menu::runMenu(char input) {
    selectButton(input);
    pressButton(input);
    displayMenu();
}



