//
// Created by honza on 01.01.2025.
//

#include "ExitGame.h"


ExitGame::ExitGame() {
    m_label = "ExitGame";
}

void ExitGame::drawButton() {
    std::cout << m_label << "\n";
}

void ExitGame::execute() {
    exit(0);
}
