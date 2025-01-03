//
// Created by honza on 03.01.2025.
//

#include "DifficultyOfGameButton.h"

#include <conio.h>

#include "../Game.h"

DifficultyOfGameButton::DifficultyOfGameButton() {
    m_label = "Difficulty of game";
    m_index = 0;
    m_difficulty.push_back("Easy");
    m_difficulty.push_back("Hard");
}

void DifficultyOfGameButton::drawButton() {
    std::cout << m_label << std::endl;
}

void DifficultyOfGameButton::execute() {
    Game::Run(1);
}

void DifficultyOfGameButton::runDifficultyOfGameMenu() {
    char input = '5';
    while (input != '\r') {
        drawDifficultyOfGameButton();
        input = getch();
        selectDifficulty(input);
    }
    getTypeOfFactory();
    Game::Run(0);
}

void DifficultyOfGameButton::drawDifficultyOfGameButton() {
    system("cls");
    std::cout << "CHOOSE YOUR DIFFICULTY " << '\n' << '\n';

    for (int i = 0; i < m_difficulty.size(); i++) {
        if (i == m_index) {
            std::cout << "> ";
        }else {
            std::cout << "  ";
        }
        std::cout << m_difficulty.at(i) << std::endl << std::endl;
    }
    std::cout << std::endl;
    std::cout << "press enter to return to the menu";
}

void DifficultyOfGameButton::selectDifficulty(char input) {
    input = static_cast<int>(input);
    switch (input) {
        case 72: { //up
            if (m_index > 0) {
                m_index--;
            }
            break;
        }
        case 80: {  // down
            if (m_index < m_difficulty.size() - 1) {
                m_index++;
            }
            break;
        }
        default:
            break;
    }
}

void DifficultyOfGameButton::getTypeOfFactory() {
    if (m_index == 0) {
        Game::m_typeOfFactory = TypeOfFactory::WeakFactory;
    }else {
        Game::m_typeOfFactory = TypeOfFactory::StrongFactory;
    }
}
