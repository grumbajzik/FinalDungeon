//
// Created by Admin on 27.12.2024.
//

#include "Game.h"

#include "Options.h"
Menu* Game::m_menu = new Menu();
Room* Game::m_room = new Room();
MonsterFactory* Game::m_monsterFactory = nullptr;
PlayerType Game::m_playerType;
std::vector<ArtilleryMonster*> Game::m_artilleryMonsters = {};
std::vector<CloseCombatEnemy*> Game::m_closeCombatEnemies = {};
TypeOfFactory Game::m_typeOfFactory = TypeOfFactory::WeakFactory;


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
//                setPlayer(Player::createPlayer(m_playerType));
                m_monsterFactory = m_monsterFactory->getFactory(m_typeOfFactory);
                startGame();
                break;
        }
    }


void Game::startGame() {
    m_room->updatePlayerPosition(3,3,true);
    Player* player = Player::createPlayer(m_playerType);

    while (true) {
        m_room->printRoom();
        player->move(m_room,'w');
        m_room->refreshRoom();
        system("pause");
    }
}
