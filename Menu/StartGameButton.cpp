//
// Created by honza on 01.01.2025.
//

#include "StartGameButton.h"
#include "../Game.h"


StartGameButton::StartGameButton() {
    m_label = "Start new Game";
}

void StartGameButton::drawButton() {
    std::cout << m_label << std::endl;
}

void StartGameButton::execute() {
    Game::Run(2);
}


