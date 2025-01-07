//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_OPTIONS_H
#define DUNGEON_OPTIONS_H


#include <string>

class Options {
    static char s_playerSkin;
public:
    static void setPlayerSkin(char skin);
    static char getPlayerSkin();
};



#endif //DUNGEON_OPTIONS_H
