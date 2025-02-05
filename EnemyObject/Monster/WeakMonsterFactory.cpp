//
// Created by honza on 03.01.2025.
//

#include "WeakMonsterFactory.h"

#include "WeakArtilleryEnemy.h"
#include "WeakBossEnemy.h"
#include "WeakCloseCombatEnemy.h"

WeakMonsterFactory::WeakMonsterFactory() {
}


ArtilleryMonster *WeakMonsterFactory::createArtilleryMonster() {
    return new WeakArtilleryEnemy(80,20,10);
}

CloseCombatEnemy *WeakMonsterFactory::createCloseCombatEnemy() {
    return new WeakCloseCombatEnemy(100,20,20);
}

BossEnemy *WeakMonsterFactory::createBossEnemy() {
    return new WeakBossEnemy(300,40,30);
}

