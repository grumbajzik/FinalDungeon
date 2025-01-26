//
// Created by honza on 26.01.2025.
//

#include "BossEnemy.h"

#include <thread>

BossEnemy::BossEnemy() {
    m_symbol = 'B';
    BossPosition = {5,5};
}

void BossEnemy::attackDiagonally(Room *room) {
    int left = 4, right= 6;
    int up = 4, down = 6;
    int index = 5;
    while(index > 1){
        room->drawAttackFromBoss(up,left, true);
        room->drawAttackFromBoss(up,right, true);
        room->drawAttackFromBoss(down,left, true);
        room->drawAttackFromBoss(down, right, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        room->drawAttackFromBoss(up,left, false);
        room->drawAttackFromBoss(up,right, false);
        room->drawAttackFromBoss(down,left, false);
        room->drawAttackFromBoss(down, right, false);
        left--;
        right++;
        up--;
        down++;
        index--;
    }
}

void BossEnemy::attackHorizontally(Room *room) {
    int left = 4, right = 6;
    int up = 4, down = 6;
    int index = 5;
    while(index > 1) {
        room->drawAttackFromBoss(left,5,true);
        room->drawAttackFromBoss(right,5,true);
        room->drawAttackFromBoss(5,up,true);
        room->drawAttackFromBoss(5,down,true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        room->drawAttackFromBoss(left,5,false);
        room->drawAttackFromBoss(right,5,false);
        room->drawAttackFromBoss(5,up,false);
        room->drawAttackFromBoss(5,down,false);
        index--;
        left--;
        right++;
        up--;
        down++;
    }
}

void BossEnemy::mekaBossInRoom(Room *room) {
    room->drawMonster(BossPosition.x, BossPosition.y, m_symbol);
}

void BossEnemy::defend(Player *player) {
    switch (Options::getPlayerType()) {
        case PlayerType::ArcherType:
            if (dynamic_cast<Archer*>(player)->getBulletPositionX() == BossPosition.x && dynamic_cast<Archer*>(player)->getBulletPositionY() == BossPosition.y) {
                m_health -= player->getStrength();
                if (m_health <= 0) {
                    player->playerKillMonster();
                    monsterDied();
                }
            }
        break;
        case PlayerType::WarriorType:
            if(dynamic_cast<Warrior*>(player)->getWeaponPositionX() == BossPosition.x && dynamic_cast<Warrior*>(player)->getWeaponPositionY() == BossPosition.y) {
                m_health -= player->getStrength();
                if (m_health <= 0) {
                    player->playerKillMonster();
                    monsterDied();
                }
            }
        break;
    }
}

void BossEnemy::attack(Player *player, Room *room) {
    attackDiagonally(room);
    attackHorizontally(room);

}

void BossEnemy::monsterDied() {
    m_symbol = ' ';
    std::cout << "closeEnemy died" << std::endl;
}

