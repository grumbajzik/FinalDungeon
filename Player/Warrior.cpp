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
    std::cout << "atack" ;
}

