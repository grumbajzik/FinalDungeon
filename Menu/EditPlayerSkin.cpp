//
// Created by honza on 01.01.2025.
//

#include "EditPlayerSkin.h"

EditPlayerSkin::EditPlayerSkin() {
    m_label = "EditPlayerSkin";
}

void EditPlayerSkin::drawButton() {
    std::cout<< m_label << std::endl;
}

void EditPlayerSkin::execute() {
    std::cout << "edit skin" << std::endl;
}


