//
// Created by honza on 02.01.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../Map/Tile.h"
#include "../Map/Room.h"
#include "../Enums/PlayerType.h"
#include "../Items/Inventory.h"


class Room;



struct Position {
    int x;
    int y;
};

class Player {

    public:

    int m_numberOfKills;

protected:

    int m_health;
    int m_maxHealth;
    int m_defense;
    int m_strength;
    Tile* playerTile;
    Position playerPosition;
    Inventory* m_inventory;

    public:

    Player();

    static Player* createPlayer(PlayerType playerType);

    void move(Room* room, char input);

    virtual void attack(Room* room, char input) = 0;

    std::string printInfo();

    void playerKillMonster();


    int getHealth();
    int getMaxHealth();
    int getDefense();
    int getStrength();
    int getPositionX();
    int getPositionY();
    void setMaxHealth(int maxHealth);
    void setHealth(int health);
    void setDefense(int defense);
    void setStrength(int strength);
    void usePotion(char input);
};



#endif //PLAYER_H
