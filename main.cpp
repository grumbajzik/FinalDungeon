#include <iostream>
#include "Game.h"
#include "Options.h"
#include "Map/Room.h"

int main() {
    Room* rom = new Room();
    rom->printRoom();
    std::cout<<"adsfaswfds"<<std::endl;
    //    Game::Run(0);

    // std::cout<<Options::getPlayerType() << " " << Options::getPlayerSkin() <<std::endl;
    // Options::setPlayerType("Archer");
    // std::cout<<Options::getPlayerType() << " " << Options::getPlayerSkin() <<std::endl;//nevytvarime instanci ale jen ji volame. Takhle to bude vypadat vsude kde ji budeme volat!!!
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}
