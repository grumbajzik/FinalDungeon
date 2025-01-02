//
// Created by Admin on 27.12.2024.
//

#include "Game.h"
Menu* Game::m_menu = new Menu();

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
                std::cout<<"JEDE HRa"<<std::endl;
                    break;
        }
    }
