//
// Created by honza on 02.01.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../Map/Tile.h"
#include "../Map/Room.h"


class Room;

enum PlayerType {
    ArcherType,
    WarriorType
};

struct Position {
    int x;
    int y;
};

class Player {

protected:

    int m_health;
    int m_defense;
    int m_strength;
    Tile* playerTile;
    Position playerPosition;

    public:

    Player();

    static Player* createPlayer(PlayerType playerType);

    void move(Room* room, char input);

    virtual void attack(Room* room, char input) = 0;

    void printInfo();


    int getHealth();
    int getDefense();
    int getStrength();
    int getPositionX();
    int getPositionY();
    void setHealth(int health);
    void setDefense(int defense);
    void setStrength(int strength);
};



#endif //PLAYER_H
