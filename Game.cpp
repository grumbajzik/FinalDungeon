//
// Created by Admin on 27.12.2024.
//

#include "Game.h"

#include <conio.h>
#include <thread>

#include "Options.h"
#include "EnemyObject/Trap/StaticTrap.h"
Menu* Game::m_menu = new Menu();
Room* Game::m_room = nullptr;
MonsterFactory* Game::m_monsterFactory = nullptr;
PlayerType Game::m_playerType;
std::vector<ArtilleryMonster*> Game::m_artilleryMonsters = {};
std::vector<CloseCombatEnemy*> Game::m_closeCombatEnemies = {};


void backgroundRefresh(Room* room, Player* player) {
    while (true) {
        room->refreshRoom(player->printInfo());
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Game::Run(int index) {
        switch (index) {
            case 0:
                m_menu->runMenu();
            //Tady to bude volat metodu která bude volat vytváření hlavního menu.
                break;
            case 1:
                m_menu->runChosenMenu();
                //Tady to bude volat metodu na vytvoření Options Menu
                break;
            case 2:
                m_monsterFactory = m_monsterFactory->getFactory(Options::getFactoryType());
                startGame();
                break;
        }
    }


void Game::startGame() {
    m_room = new Room();
    m_room->updatePlayerPosition(3,3,true);
    Player* player = Player::createPlayer(m_playerType);
    ArtilleryMonster* arMonster = m_monsterFactory->createArtilleryMonster();
    CloseCombatEnemy* clMonster = m_monsterFactory->createCloseCombatEnemy();
    StaticTrap* trap = StaticTrap::createTrap();

    trap->makeTrapInRoom(m_room);
    arMonster->makeMonsterInRoom(m_room);
    clMonster->makeMonsterInRoom(m_room);

    m_room->printRoom();
    std::thread refreshThread(backgroundRefresh, m_room, player);
    std::thread inputThread(playerInput, player);

    while (true/*player->getHealth()>0*/) {

        arMonster->attack(player,m_room);
        arMonster->defend(player);
//        std::thread closeCombatThread(&CloseCombatEnemy::attack, clMonster, std::ref(player), std::ref(m_room));
        clMonster->attack(player, m_room);
//        closeCombatThread.detach();
        trap->treatPlayer(player);
    }
}

void Game::playerInput(Player *player) {
    while (player->getHealth()>0) {
        char input = getch();
        player->move(m_room, input);
        player->attack(m_room, input);
    }
}
