//
// Created by honza on 03.01.2025.
//

#include "CloseCombatEnemy.h"

CloseCombatEnemy::CloseCombatEnemy() {
    m_symbol = 'C';
}

void CloseCombatEnemy::makeMonsterInRoom(Room *room) {
    int roomSizeX = room->getSizeOfRoomX();
    int roomSizeY = room->getSizeOfRoomY();
    bool isSign = true;

    closeCombatPosition.x = std::rand() % roomSizeX;
    closeCombatPosition.y = std::rand() % roomSizeY;

    while (isSign) {
        if (room->getRoom().at(closeCombatPosition.x).at(closeCombatPosition.y)->getIcon() == ' ') {
            isSign = false;
        } else {
            closeCombatPosition.x = std::rand() % roomSizeX; // Náhodný řádek
            closeCombatPosition.y = std::rand() % roomSizeY; // Náhodný sloupec
        }
    }
    room->drawMonster(closeCombatPosition.x,closeCombatPosition.y,m_symbol);
}

void CloseCombatEnemy::attack(Player *player, Room *room) {
    int healtAfterDamage = player->getHealth()- m_strength;
    int lastX = closeCombatPosition.x;
    int lastY = closeCombatPosition.y;

    if(closeCombatPosition.x != player->getPositionX()) {
        if (closeCombatPosition.x > player->getPositionX()) {
            closeCombatPosition.x--;
        }else {
            closeCombatPosition.x++;
        }
    }
    if(closeCombatPosition.y != player->getPositionY()) {
        if (closeCombatPosition.y > player->getPositionY()) {
            closeCombatPosition.y--;
        }else {
            closeCombatPosition.y++;
        }
    }

    room->updateMonsterPosition(closeCombatPosition.x, closeCombatPosition.y,lastX,lastY, m_symbol);
    if(player->getPositionX() == closeCombatPosition.x && player->getPositionY() == closeCombatPosition.y) {
        player->setHealth(healtAfterDamage);
    }
}
