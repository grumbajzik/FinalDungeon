//
// Created by honza on 02.01.2025.
//

#include "Archer.h"

#include <conio.h>
#include <thread>

Archer::Archer(int health, int defence, int strength) {
    m_health = health;
    m_defense = defence;
    m_strength = strength;
    m_attackRange = 4;
}

void Archer::attack(Room* room, char input) {
    int arrow = static_cast<int>(input);
    int direction = -1;
    bulletPosition.x = playerPosition.x;
    bulletPosition.y = playerPosition.y;


    room->drawPlayerAttackOnRange(m_attackRange,bulletPosition.x,bulletPosition.y,direction, false);

    switch (input) {
        case 72: {
            bulletPosition.x--;
            direction = 1; //up
            std::thread shootingThread(&Room::drawPlayerAttackOnRange,
                                       room,
                                       m_attackRange,
                                       (bulletPosition.x),  // Předání jako reference
                                       (bulletPosition.y),
                                       direction,
                                       true);
            shootingThread.detach();
            break;
        }
        case 80: {
            bulletPosition.x++;
            direction = 2; //down
            std::thread shootingThread(&Room::drawPlayerAttackOnRange,
                                       room,
                                       m_attackRange,
                                       (bulletPosition.x),  // Předání jako reference
                                       (bulletPosition.y),
                                       direction,
                                       true);
            shootingThread.detach();
            break;
        }
        case 75: {
            bulletPosition.y--;
            direction = 3; //left
            std::thread shootingThread(&Room::drawPlayerAttackOnRange,
                                       room,
                                       m_attackRange,
                                       (bulletPosition.x),  // Předání jako reference
                                       (bulletPosition.y),
                                       direction,
                                       true);
            shootingThread.detach();
            break;
        }
        case 77: {
            bulletPosition.y++;
            direction = 4; //right
            std::thread shootingThread(&Room::drawPlayerAttackOnRange,
                                       room,
                                       m_attackRange,
                                       (bulletPosition.x),  // Předání jako reference
                                       (bulletPosition.y),
                                       direction,
                                       true);
            shootingThread.detach();
            break;
        }
        default:
            break;
    }
}

