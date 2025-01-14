//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_GAME_H
#define DUNGEON_GAME_H
#include "Menu/Menu.h"

#include "EnemyObject/Monster/ArtilleryMonster.h"
#include "EnemyObject/Monster/CloseCombatEnemy.h"
#include "EnemyObject/Monster/MonsterFactory.h"
#include "Map/Room.h"
#include "Player/Player.h"


class Game {
    static Menu* m_menu;
    Player* m_player;
    static Room* m_room;
    static MonsterFactory* m_monsterFactory;
    static std::vector<ArtilleryMonster*> m_artilleryMonsters;
    static std::vector<CloseCombatEnemy*> m_closeCombatEnemies;
public:
    static PlayerType m_playerType;
    static TypeOfFactory m_typeOfFactory;

    static void Run(int index);
    static void startGame();

};


#endif //DUNGEON_GAME_H
