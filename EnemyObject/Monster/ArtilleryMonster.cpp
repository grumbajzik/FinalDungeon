//
// Created by honza on 03.01.2025.
//

#include "ArtilleryMonster.h"

#include <thread>


ArtilleryMonster::ArtilleryMonster() {
    m_symbol = 'A';
    std::time(&m_lastAttack);
}

void ArtilleryMonster::makeMonsterInRoom(Room *room) {
    m_room = room;
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
    room->drawMonster(artilleryPosition.x,artilleryPosition.y,m_symbol);
}

void ArtilleryMonster::attack(Player *player, Room *room) {
    std::time_t now;
    time(&now);
    if(std::difftime(now, m_lastAttack) > 1) {
        int roomSizeX = room->getSizeOfRoomX() - 2;
        int roomSizeY = room->getSizeOfRoomY() - 2;
        int healthAfterDmg = player->getHealth() - m_strength;

        attackingPosition.x = std::rand() % roomSizeX+1;
        attackingPosition.y = std::rand() % roomSizeY+1;
        m_artilleryAttackTile = room->getRoom().at(attackingPosition.x).at(attackingPosition.y)->getIcon();
        m_lastAttack = now;
        std::thread artilleryThread(&ArtilleryMonster::threadAttack, this, player, room,healthAfterDmg);
        artilleryThread.detach();
    }
}



void ArtilleryMonster::threadAttack(Player *player, Room *room, int healthAfterDmg) {


    room->drawArtilleryAttack(attackingPosition.x, attackingPosition.y, 1, m_artilleryAttackTile);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    room->drawArtilleryAttack(attackingPosition.x, attackingPosition.y, 2, m_artilleryAttackTile);

    if(attackingPosition.x == player->getPositionX() && attackingPosition.y == player->getPositionY()) {
        player->setHealth(healthAfterDmg);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    room->drawArtilleryAttack(attackingPosition.x, attackingPosition.y, 3, m_artilleryAttackTile);
}

void ArtilleryMonster::defend(Player *player) {
    switch (Options::getPlayerType()) {
        case PlayerType::ArcherType:
            if (dynamic_cast<Archer*>(player)->getBulletPositionX() == artilleryPosition.x && dynamic_cast<Archer*>(player)->getBulletPositionY() == artilleryPosition.y) {
                m_health -= player->getStrength();
                if (m_health <= 0) {
                    player->playerKillMonster();
                    monsterDied();
                }
            }
            break;
        case PlayerType::WarriorType:
            if(dynamic_cast<Warrior*>(player)->getWeaponPositionX() == artilleryPosition.x && dynamic_cast<Warrior*>(player)->getWeaponPositionY() == artilleryPosition.y) {
                m_health -= player->getStrength();
                if (m_health <= 0) {
                    player->playerKillMonster();
                    monsterDied();
                }
            }
            break;
    }
}

void ArtilleryMonster::monsterDied() {
    m_room->getRoom();
    delete this;
}





