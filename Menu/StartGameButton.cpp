//
// Created by honza on 01.01.2025.
//

#include "StartGameButton.h"


StartGameButton::StartGameButton() {
    m_label = "Start new Game";
}

void StartGameButton::drawButton() {
    std::cout << m_label << std::endl;
}

void StartGameButton::execute() {
    std::cout << "start" << std::endl;
}


