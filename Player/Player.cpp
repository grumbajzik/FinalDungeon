//
// Created by honza on 02.01.2025.
//

#include "Player.h"

#include "Archer.h"
#include "Warrior.h"

Player::Player() {
    playerPosition = {3,3};
}


Player *Player::createPlayer(PlayerType playerType) {
    switch (playerType) {
        case ArcherType:
            return new Archer(50,50,50);
            break;
        case WarriorType:
            return new Warrior(50,50,50);
            break;
        default:
            std::cerr << "Unknown Player Type" << std::endl;
            return nullptr;
            break;
    }
}


void Player::move(Room* room, char input) {
    //    std::this_thread::sleep_for(std::chrono::milliseconds(100));
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




