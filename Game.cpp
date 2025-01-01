//
// Created by Admin on 27.12.2024.
//

#include "Game.h"


Game::Game() {
    Menu* m_menu = new Menu();
}

void Game::Run(int index) {
    while (true) {
        char input = _getch();

        switch (index) {
            case 0:
                m_menu->runMenu(input);
            //Tady to bude volat metodu která bude volat vytváření hlavního menu.
            break;
            case 1:
                //Tady to bude volat metodu na vytvoření Options Menu
                    break;
            case 2:
                //Tady se bude volat metoda pro hru
                    break;
        }
    }
}