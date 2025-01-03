//
// Created by honza on 03.01.2025.
//

#include "HowToPlayButton.h"

#include <conio.h>

#include "../Game.h"

HowToPlayButton::HowToPlayButton() {
    m_label = "How To Play";
}

void HowToPlayButton::execute() {
    Game::Run(1);
}

void HowToPlayButton::drawButton() {
    std::cout << m_label << std::endl;
}

void HowToPlayButton::runHowToPlayMenu() {
    system("cls");
    char input = '5';
    std::cout << "HOW TO PLAY" << std::endl << std::endl;
    drawMenu();
    std::cout << "\n" <<"press enter to return"<< std::endl;
    while (input != '\r') {
        input = getch();
    }
    Game::Run(0);
}

void HowToPlayButton::drawMenu() {
    std::cout << "50" << std::endl;
}

