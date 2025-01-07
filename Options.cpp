//
// Created by Admin on 27.12.2024.
//

#include <iostream>
#include "Options.h"

char Options::s_playerSkin = '*';


char Options::getPlayerSkin() {
    return s_playerSkin;
}



void Options::setPlayerSkin(char skin) {
    s_playerSkin = skin;
}
