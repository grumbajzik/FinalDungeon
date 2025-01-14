//
// Created by honza on 14.01.2025.
//

#ifndef STATICTRAP_H
#define STATICTRAP_H
#include "../../Map/Room.h"

struct TrapPosition {
    int x;
    int y;
};

class StaticTrap {

    TrapPosition trapPosition;

    int m_damage;
    char m_symbol;

    public:

    StaticTrap();

    static StaticTrap * createTrap();

    void makeTrapInRoom(Room* room);

    void treatPlayer(Player* player);
};



#endif //STATICTRAP_H
