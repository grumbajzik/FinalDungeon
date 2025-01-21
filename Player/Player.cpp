//
// Created by honza on 02.01.2025.
//

#include "Player.h"

#include "Archer.h"
#include "Warrior.h"

Player::Player() {
    playerPosition = {3,3};
    m_numberOfKills = 0;
}


Player *Player::createPlayer(PlayerType playerType) {
    switch (playerType) {
        case PlayerType::ArcherType:
            return new Archer(80,30,40);
            break;
        case PlayerType::WarriorType:
            return new Warrior(100,50,50);
            break;
        default:
            std::cerr << "Unknown Player Type" << std::endl;
            return nullptr;
            break;
    }
}


void Player::move(Room* room, char input) {
    room->updatePlayerPosition(playerPosition.x,playerPosition.y, false);

    switch (input) {
        case 'w':
            if(playerPosition.x > 1) {
                playerPosition.x -= 1;
            }
        break;
        case 's':
            if(playerPosition.x < room->getSizeOfRoomX()-2){
                playerPosition.x += 1;
            }
        break;
        case 'a':
            if(playerPosition.y > 1) {
                playerPosition.y -= 1;
            }
        break;
        case 'd':
            if(playerPosition.y < room->getSizeOfRoomY()-2){
                playerPosition.y += 1;
            }
        break;
        default:
            break;
        }
    room->updatePlayerPosition(playerPosition.x,playerPosition.y, true);
}

std::string Player::printInfo() {
    return "X: " + std::to_string(playerPosition.x) + " Y: " + std::to_string(playerPosition.y) + "\n" +
    "health: " + std::to_string(m_health) + "\n" +
    "defence: " + std::to_string(m_defense) + "\n"+
    "strength: " + std::to_string(m_strength) +  "\n"+
    "kills: " + std::to_string(m_numberOfKills) + "\n";
}

void Player::playerKillMonster() {
    m_numberOfKills++;
}

//getry
int Player::getHealth() {
    return m_health;
}
int Player::getMaxHealth() {
    return m_maxHealth;
}
int Player::getDefense() {
    return m_defense;
}
int Player::getStrength() {
    return m_strength;
}
int Player::getPositionX() {
    return playerPosition.x;
}
int Player::getPositionY() {
    return playerPosition.y;
}
//setry
void Player::setHealth(int health) {
    m_health = health;
}
void Player::setMaxHealth(int maxHealth) {
    m_maxHealth = maxHealth;
}
void Player::setDefense(int defense) {
    m_defense = defense;
}
void Player::setStrength(int strength) {
    m_strength = strength;
}






