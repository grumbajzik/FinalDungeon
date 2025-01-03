//
// Created by Admin on 27.12.2024.
//

#include "Game.h"

#include "Options.h"
Menu* Game::m_menu = new Menu();
Player* Game::m_player = nullptr;
PlayerType Game::m_playerType;
std::vector<ArtilleryMonster*> Game::m_artilleryMonsters = {};
std::vector<CloseCombatEnemy*> Game::m_closeCombatEnemies = {};

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
                m_player->createPlayer(m_playerType);
                std:: cout << "Player skin: "<<Options::getPlayerSkin() << std::endl;
                std::cout<<"JEDE HRa"<<std::endl;
                system("pause");
                break;
        }
    }
