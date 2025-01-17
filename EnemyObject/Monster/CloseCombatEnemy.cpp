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

    m_previousTile = room->getRoom().at(closeCombatPosition.x).at(closeCombatPosition.y)->getIcon();

    if (m_previousTile == 'C') {
        m_previousTile = ' ';
    }

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

    room->updateMonsterPosition(closeCombatPosition.x, closeCombatPosition.y,lastX,lastY, m_symbol,m_previousTile);
    if(player->getPositionX() == closeCombatPosition.x && player->getPositionY() == closeCombatPosition.y) {
        player->setHealth(healtAfterDamage);
    }
}

void CloseCombatEnemy::defend(Player *player) {
    switch (Options::getPlayerType()) {
        case PlayerType::ArcherType:
            if (dynamic_cast<Archer*>(player)->getBulletPositionX() == closeCombatPosition.x && dynamic_cast<Archer*>(player)->getBulletPositionY() == closeCombatPosition.y) {
                m_health -= player->getStrength();
                if (m_health <= 0) {
                    monsterDied();
                }
            }
        break;
        case PlayerType::WarriorType:
            if(dynamic_cast<Warrior*>(player)->getWeaponPositionX() == closeCombatPosition.x && dynamic_cast<Warrior*>(player)->getWeaponPositionY() == closeCombatPosition.y) {
                m_health -= player->getStrength();
                if (m_health <= 0) {
                    monsterDied();
                }
            }
        break;
    }
}

void CloseCombatEnemy::monsterDied() {
    m_symbol = ' ';
    std::cout << "closeEnemy died" << std::endl;
}