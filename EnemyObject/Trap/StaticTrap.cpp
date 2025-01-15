//
// Created by honza on 14.01.2025.
//

#include "StaticTrap.h"

StaticTrap::StaticTrap() {
    m_damage = 30;
    m_symbol = 'S';
}

StaticTrap *StaticTrap::createTrap() {
    return new StaticTrap();
}

void StaticTrap::makeTrapInRoom(Room *room) {
    unsigned int sizeX = room->getSizeOfRoomX();
    unsigned int sizeY = room->getSizeOfRoomY();
    bool isSign = true;

    trapPosition.x = std::rand() % sizeX; // Náhodný řádek
    trapPosition.y = std::rand() % sizeY;

    while (isSign) {
        if (room->getRoom().at(trapPosition.x).at(trapPosition.y)->getIcon() == ' ') {
            isSign = false;
        } else {
            trapPosition.x = std::rand() % sizeX; // Náhodný řádek
            trapPosition.y = std::rand() % sizeY; // Náhodný sloupec
        }
    }
    room->drawTrap(trapPosition.x,trapPosition.y,m_symbol);
}

void StaticTrap::treatPlayer(Player *player) {
    int healthAfterDmg = player->getHealth() - m_damage;
    if (player->getPositionX() == trapPosition.x && player->getPositionY() == trapPosition.y) {
        player->setHealth(healthAfterDmg);
    }
}
