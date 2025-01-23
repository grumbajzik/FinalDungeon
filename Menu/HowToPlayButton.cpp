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
    std::cout << "To move with your character you have to use buttons WSAD" << std::endl;
    std::cout << "W - move up, S - move down, A - move left, D - move right" << std::endl;
    std::cout << "To attack/shoot you have to use arrows in the same way like at moving" << std::endl;
    std::cout << "You can choose between two difficulties, hard and easy" << std::endl;
    std::cout << "Also you can choose your character skin, between * , + , @ , $ " << std::endl;
    std::cout << "You have to beat monsters also, they look like A and C, also traps are there, they look like S " << std::endl;
}

