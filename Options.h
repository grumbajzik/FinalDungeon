//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_OPTIONS_H
#define DUNGEON_OPTIONS_H


#include <string>
#include "Enums/PlayerType.h"
#include "Enums/FactoryType.h"

class Options {
    static char s_playerSkin;
    static PlayerType s_playerType;
    static FactoryType s_factoryType;
public:
    static void setPlayerSkin(char skin);
    static char getPlayerSkin();
    static void setPlayerType(PlayerType type);
    static PlayerType getPlayerType();
    static void setFactoryType(FactoryType factoryType);
    static FactoryType getFactoryType();
};



#endif //DUNGEON_OPTIONS_H
