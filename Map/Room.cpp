//
// Created by Admin on 14.10.2024.
//

#include <vector>
#include <stdlib.h> // pro rand()
#include <ctime>   // pro time()
#include "Room.h"

#include <chrono>
#include <conio.h>
#include <thread>

#include "../Options.h"
#include "../Player/Player.h"



Room::Room() {
    m_room = generateRoom();
    m_originalRoom = m_room;
    m_id = s_id++;
    m_lastAttack = {-1,-1};
    m_playerSkinInRoom = new Tile(Options::getPlayerSkin());
}

int Room::getId(){
    return m_id;
}

void Room::printRoom() {
    clearRoom();
    for (auto& row : m_room) {
        for (auto& cell : row) {
            std::cout << cell->getIcon() << " ";
        }
        std::cout << std::endl;
    }
}

void Room::refreshRoom(std::string info) {
    std::lock_guard<std::mutex> lock(m_consoleMutex); // Zamknutí přístupu
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, {0, 0});
    for (auto &row: m_room) {
        std::string value = "";
        for (auto &cell: row) {
            value += cell->getIcon();
            value += ' ';
        }
        std::cout << value << std::endl;
    }
    if(info != ""){
        std::cout << info;
    }
}

std::vector<std::vector<Tile*>> Room::generateRoom() {

    std::srand(std::time(nullptr));
    int rows = rand() % 4 + 13;
    int cols = rand() % 4 + 13;

    std::vector<std::vector<Tile*>> newRoom(rows, std::vector<Tile*>(cols));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++) {
            if(j==0 || j==cols-1 || i==0 || i==rows-1) {
                newRoom.at(i).at(j) = new Tile('#');
            }else{
                newRoom[i][j]= new Tile(' ');
            }
        }
    }
    return newRoom;
}

std::vector<std::vector<Tile*>> Room::getRoom() {
    return m_room;
}

void Room::updatePlayerPosition(int x,int y, bool newPosition) {
    if (newPosition) {
        m_playerPreviousMove = m_originalRoom.at(x).at(y);
        m_room.at(x).at(y) = m_playerSkinInRoom;
    } else {
        m_room.at(x).at(y) = m_playerPreviousMove;
    }
}

void Room::drawPlayerAttack(int x, int y, bool isAttack, bool isUp) {
    if (m_lastAttack.first != -1 && m_lastAttack.second != -1) {
        if(m_room.at(m_lastAttack.first).at(m_lastAttack.second)->getIcon() == Options::getPlayerSkin()){
            m_room.at(m_lastAttack.first).at(m_lastAttack.second) = m_playerSkinInRoom;
        } else{
            m_room.at(m_lastAttack.first).at(m_lastAttack.second) = m_attackPrevoiousTile;
        }

    }

    if (x < m_room.size()-1 && y < m_room[0].size()-1 && x > 0 && y > 0) {
        if (isAttack) {
            m_attackPrevoiousTile = m_room.at(x).at(y);
            if (isUp) {
                m_room.at(x).at(y) = new Tile('|');
            }else {
                m_room.at(x).at(y) = new Tile('-');
            }
            m_lastAttack = {x,y};
        }else {
            m_lastAttack = {-1,-1};
        }
    }
}

void Room::drawPlayerAttackOnRange(int range,int x,int y,int direction,bool isAttack) {
    if (isAttack) {
        for (int i = 0; i < range; i++) {
            if (m_room.at(x).at(y)->getIcon() != '#') {
                m_attackPrevoiousTile = m_originalRoom.at(x).at(y);
                m_room.at(x).at(y) = new Tile('o');
                refreshRoom("");
                std::this_thread::sleep_for(std::chrono::milliseconds(70));
                m_room.at(x).at(y) = m_attackPrevoiousTile;
                switch (direction) {
                    case 1:
                        x--;
                        break;
                    case 2:
                        x++;
                        break;
                    case 3:
                        y--;
                        break;
                    case 4:
                        y++;
                        break;
                    default:
                        break;
                }
            }else{
                m_room.at(x).at(y) = m_originalRoom.at(x).at(y);
            }
        }
    }
}

void Room::clearRoom() {
    system("cls");
}

int Room::getSizeOfRoomX() {
    return m_room.size();
}

int Room::getSizeOfRoomY() {
    return m_room[0].size();
}

void Room::drawTrap(int x, int y, char trap) {
    m_originalRoom.at(x).at(y) = new Tile(trap);
    m_room.at(x).at(y) = new Tile(trap);
}

void Room::drawMonster(int x, int y, char sign) {
    m_originalRoom.at(x).at(y) = new Tile(sign);
    m_room.at(x).at(y) = new Tile(sign);
}

void Room::updateMonsterPosition(int newX, int newY, int lastX, int lastY,char monsterChar, char previousTile) {
    if (m_room.at(lastX).at(lastY) == m_playerSkinInRoom) {
        m_room.at(lastX).at(lastY) = m_playerPreviousMove;
    }else {
        m_room.at(lastX).at(lastY) = new Tile(previousTile);
    }
    m_room.at(newX).at(newY) = new Tile(monsterChar);
}


void Room::drawArtilleryAttack(int x, int y, int stateOfAttack, char previousTile) {

    switch(stateOfAttack) {
        case 1:
            m_room.at(x).at(y) = new Tile('X');
            break;
        case 2:
            m_room.at(x).at(y) = new Tile('H');
            break;
        case 3:
            m_room.at(x).at(y) = new Tile(previousTile);
            break;
    }
}

int Room::s_id = 0;
