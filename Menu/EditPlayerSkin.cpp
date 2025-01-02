//
// Created by honza on 01.01.2025.
//

#include "EditPlayerSkin.h"

#include "../Game.h"

EditPlayerSkin::EditPlayerSkin() {
    m_label = "EditPlayerSkin";
    m_skinIndex = 0;
    m_skins.push_back('*');
    m_skins.push_back('@');
    m_skins.push_back('$');
    m_skins.push_back('+');
    m_chosenSkin = m_skins[m_skinIndex];
}

void EditPlayerSkin::drawButton() {
    std::cout<< m_label << std::endl;
}

void EditPlayerSkin::execute() {
    Game::Run(1);
}

void EditPlayerSkin::drawMenuWithSkins() {
    system("cls");
    std::cout << "CHOOSE YOUR SKIN " << '\n' << '\n';

    for (int i = 0; i < m_skins.size(); i++) {
        if (i == m_skinIndex) {
            std::cout << "> ";
        }else {
            std::cout << "  ";
        }
        std::cout << m_skins.at(i) << std::endl << std::endl;
    }
    std::cout << std::endl;
    std::cout << "press enter to return to the menu";
}

void EditPlayerSkin::selectSkin(char input) {
    input = static_cast<int>(input);
    switch (input) {
        case 72: { //up
            if (m_skinIndex > 0) {
                m_skinIndex--;
            }
            break;
        }
        case 80: {  // down
            if (m_skinIndex < m_skins.size() - 1) {
                m_skinIndex++;
            }
            break;
        }
        default:
            break;
    }
    m_chosenSkin = m_skins[m_skinIndex];
}

void EditPlayerSkin::runEditPlayerSkinMenu() {
    char input = '5';

    while (input != '\r') {
        drawMenuWithSkins();
        input = _getch();
        selectSkin(input);
    }
    Game::Run(0);
}

