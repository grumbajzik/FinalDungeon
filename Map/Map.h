//
// Created by Admin on 20.01.2025.
//

#ifndef DUNGEON_MAP_H
#define DUNGEON_MAP_H


#include <vector>
#include "Room.h"

class Map {
    std::vector<Room*> m_map = {new Room, new Room, new Room, new Room};

public:
    std::vector<Room*> getMap(){
        return m_map;
    }
};


#endif //DUNGEON_MAP_H
