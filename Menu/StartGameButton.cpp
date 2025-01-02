//
// Created by honza on 01.01.2025.
//

#include "StartGameButton.h"
#include "../Game.h"


StartGameButton::StartGameButton() {
    m_label = "Start new Game";
    m_index = 0;
    m_typeOfPlayer.push_back("Archer");
    m_typeOfPlayer.push_back("Warrior");
}

void StartGameButton::drawButton() {
    std::cout << m_label << std::endl;
}

void StartGameButton::execute() {
    Game::Run(1);
}

void StartGameButton::drawMenuWithTypeOfPlayer() {
    system("cls");
    std::cout << "CHOSE TYPE OF PLAYER" << '\n' << '\n';

    for (int i = 0; i < m_typeOfPlayer.size(); i++) {
        if (m_index == i ) {
            std::cout << " >";
        }else {
            std::cout << "  ";
        }
        std::cout << m_typeOfPlayer[i] << '\n' << std::endl;
    }
}

void StartGameButton::selectTypeOfPlayer(char input) {
    input = static_cast<int>(input);
    switch (input) {
        case 72: { //up
            if (m_index > 0) {
                m_index--;
            }
            break;
        }
        case 80: {  // down
            if (m_index < m_typeOfPlayer.size() - 1) {
                m_index++;
            }
            break;
        }
        default:
            break;
    }
}

void StartGameButton::runEditPlayerSkinMenu() {
    char input = '5';

    while(input != '\r') {
        drawMenuWithTypeOfPlayer();
        input = getch();
        selectTypeOfPlayer(input);
    }
    Game::Run(2);
}






