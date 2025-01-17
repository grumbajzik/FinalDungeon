//
// Created by Admin on 27.12.2024.
//

#include <iostream>
#include "Options.h"

char Options::s_playerSkin = '*';
FactoryType Options::s_factoryType = FactoryType::WeakFactory; // Replace DEFAULT with the appropriate value
PlayerType Options::s_playerType = PlayerType::WarriorType;
char Options::getPlayerSkin() {
    return s_playerSkin;
}

void Options::setPlayerSkin(char skin) {
    s_playerSkin = skin;
}

void Options::setPlayerType(PlayerType type) {
    s_playerType = type;

}

PlayerType Options::getPlayerType() {
    return s_playerType;
}

void Options::setFactoryType(FactoryType factoryType) {
    s_factoryType = factoryType;
}

FactoryType Options::getFactoryType() {
    return s_factoryType;
}

