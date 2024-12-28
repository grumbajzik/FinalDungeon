//
// Created by Admin on 27.12.2024.
//

#include <iostream>
#include "Options.h"

char Options::s_playerSkin = '*';
std::string Options::s_playerType = "Warrior";


char Options::getPlayerSkin() {
    return s_playerSkin;
}

std::string Options::getPlayerType() {
    std::cout<<s_playerType<<std::endl;
    return s_playerType;
}

void Options::setPlayerSkin(char skin) {
    s_playerSkin = skin;
}

void Options::setPlayerType(std::string type) {
    s_playerType = type;
}