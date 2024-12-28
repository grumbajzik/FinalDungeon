//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_OPTIONS_H
#define DUNGEON_OPTIONS_H


#include <string>

class Options {
    static char s_playerSkin;
    static std::string s_playerType;//FIXME bude potřeba změnit na enum který se bude používat při vytváření hráče
public:
    static void setPlayerSkin(char skin);
    static void setPlayerType(std::string type);
    static char getPlayerSkin();
    static std::string getPlayerType();
};



#endif //DUNGEON_OPTIONS_H
