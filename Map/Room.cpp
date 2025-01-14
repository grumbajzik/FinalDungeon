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

void Room::refreshRoom() {
//    std::lock_guard<std::mutex> lock(m_consoleMutex); // Zamknutí přístupu
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

//void Room::drawPlayerAttack(int x, int y, bool isAttack) {
//
//    if (m_lastAttack.first != -1 && m_lastAttack.second != -1) {
//        m_room.at(m_lastAttack.first).at(m_lastAttack.second) = m_attackPrevoiousSign;
//    }
//
//    if (x < m_room.size()-1 && y < m_room[0].size()-1 && x > 0 && y > 0) {
//        if (isAttack) {
//            m_attackPrevoiousSign = m_room.at(x).at(y);
//            m_room.at(x).at(y) = '-';
//            m_lastAttack = {x,y};
//        }else {
//            m_lastAttack = {-1,-1};
//        }
//    }
//}

void Room::drawPlayerAttackOnRange(int range,int x,int y,int direction,bool isAttack) {
    if (isAttack) {
        for (int i = 0; i < range; i++) {
            if (m_room.at(x).at(y)->getIcon() != '#') {
                m_attackPrevoiousTile = m_originalRoom.at(x).at(y);
                m_room.at(x).at(y) = new Tile('o');
                refreshRoom();
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

//void Room::drawTrap(int x, int y, char trap) {
//    m_originalRoom.at(x).at(y) = trap;
//    m_room.at(x).at(y) = trap;
//}

//void Room::drawMonster(int x, int y, char sign) {
//    m_originalRoom.at(x).at(y) = sign;
//    m_room.at(x).at(y) = sign;
//}

//void Room::drawArtilleryAttack(int x, int y, bool warning) {
//    if (warning) {
//        m_originalRoom.at(x).at(y) = 'X';
//        m_room.at(x).at(y) = 'X';
//    }else {
//        m_originalRoom.at(x).at(y) = '@';
//        m_room.at(x).at(y) = '@';
//    }
//}




int Room::s_id = 0;//
// Created by Admin on 04.01.2025.
//

#include "Room.h"
