//
// Created by honza on 03.01.2025.
//

#include "ArtilleryMonster.h"

#include <thread>

ArtilleryMonster::ArtilleryMonster() {
    m_artillerySign = 'A';
}

void ArtilleryMonster::makeMonsterInRoom(Room *room) {
    int roomSizeX = room->getSizeOfRoomX();
    int roomSizeY = room->getSizeOfRoomY();
    bool isSign = true;

    artilleryPosition.x = std::rand() % roomSizeX;
    artilleryPosition.y = std::rand() % roomSizeY;

    while (isSign) {
        if (room->getRoom().at(artilleryPosition.x).at(artilleryPosition.y)->getIcon() == ' ') {
            isSign = false;
        } else {
            artilleryPosition.x = std::rand() % roomSizeX; // Náhodný řádek
            artilleryPosition.y = std::rand() % roomSizeY; // Náhodný sloupec
        }
    }
    room->drawMonster(artilleryPosition.x,artilleryPosition.y,m_artillerySign);
}

void ArtilleryMonster::attack(Player *player, Room *room) {
    int roomSizeX = room->getSizeOfRoomX()-1;
    int roomSizeY = room->getSizeOfRoomY()-1;
    int healthAfterDmg = player->getHealth()- m_strength;

    attackingPosition.x = std::rand() % roomSizeX;
    attackingPosition.y = std::rand() % roomSizeY;

    m_artilleryAttackTile = room->getRoom().at(attackingPosition.x).at(attackingPosition.y)->getIcon();

    room->drawArtilleryAttack(attackingPosition.x,attackingPosition.y,1, m_artilleryAttackTile);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    room->drawArtilleryAttack(attackingPosition.x,attackingPosition.y,2,m_artilleryAttackTile);

    if(attackingPosition.x == player->getPositionX() && attackingPosition.y == player->getPositionY()) {
        player->setHealth(healthAfterDmg);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    room->drawArtilleryAttack(attackingPosition.x,attackingPosition.y,3,m_artilleryAttackTile);
}

