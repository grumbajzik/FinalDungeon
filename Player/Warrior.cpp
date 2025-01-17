//
// Created by honza on 02.01.2025.
//

#include "Warrior.h"

Warrior::Warrior(int health, int defence, int strength) {
    m_health = health;
    m_defense = defence;
    m_strength = strength;
}

void Warrior::attack(Room *room, char input) {
    int arrow = static_cast<int>(input);
    weaponPosition.x = playerPosition.x;
    weaponPosition.y = playerPosition.y;
    room->drawPlayerAttack(weaponPosition.x,weaponPosition.y, false, false);

    switch (arrow) {
        case 72:
            //sipka nahoru
                weaponPosition.x -= 1;
            room->drawPlayerAttack(weaponPosition.x,weaponPosition.y, true, true);
        break;
        case 80:
            //sipka dolu
                weaponPosition.x += 1;
            room->drawPlayerAttack(weaponPosition.x,weaponPosition.y, true, true);
        break;
        case 75:
            //sipka doleva
                weaponPosition.y -= 1;
            room->drawPlayerAttack(weaponPosition.x,weaponPosition.y, true, false);
        break;
        case 77:
            //sipka doprava
                weaponPosition.y += 1;
            room->drawPlayerAttack(weaponPosition.x,weaponPosition.y, true, false);
        break;
        default:
            room->drawPlayerAttack(weaponPosition.x,weaponPosition.y, false, false);
        break;
    }
}

int Warrior::getWeaponPositionX() {
    return weaponPosition.x;
}
int Warrior::getWeaponPositionY() {
    return weaponPosition.y;
}

