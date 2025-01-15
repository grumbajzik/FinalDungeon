//
// Created by Admin on 14.10.2024.
//

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "mutex"
#include "Tile.h"
#include "../Player/Player.h"


class Room{
public:
    Room();
    void printRoom();
    void refreshRoom(std::string info);
    int getId();
    std::vector<std::vector<Tile*>> getRoom();
    void updatePlayerPosition(int x,int y, bool newPosition);
    void drawPlayerAttack(int x,int y, bool isAttack, bool isUp);
    void drawPlayerAttackOnRange(int range,int x,int y,int direction,bool isAttack);
    void drawTrap(int x, int y, char trap);
    void drawMonster(int x, int y, char sign);
    void drawArtilleryAttack(int x, int y, bool warning);

    int getSizeOfRoomX();
    int getSizeOfRoomY();

private:
    std::mutex m_consoleMutex;
    std::vector<std::vector<Tile*>> m_room;
    std::vector<std::vector<Tile*>> m_originalRoom;
    Tile* m_playerSkinInRoom;
    static int s_id;
    int m_id ;
    std::pair<int,int> m_lastAttack; //na uchovani posledniho utoku na blizko
    Tile* m_playerPreviousMove;
    Tile* m_attackPrevoiousTile = nullptr;
    std::vector<std::vector<Tile*>> generateRoom();
    void clearRoom();
};

#endif