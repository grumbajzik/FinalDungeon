//
// Created by honza on 02.01.2025.
//

#include "Player.h"

#include "Archer.h"
#include "Warrior.h"

Player::Player() {
}


Player *Player::createPlayer(PlayerType playerType ) {
    switch (playerType) {
        case Archertype:
            return new Archer(50,50,50);
            break;
        case Warriortype:
            return new Warrior(50,50,50);
            break;
        default:
            std::cerr << "Unknown Player Type" << std::endl;
            return nullptr;
            break;
    }
}


