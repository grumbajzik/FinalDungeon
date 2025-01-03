//
// Created by honza on 03.01.2025.
//

#include "StrongMonsterFactory.h"

#include "StrongArtilleryEnemy.h"
#include "StrongCloseCombatEnemy.h"

StrongMonsterFactory::StrongMonsterFactory() {
}

ArtilleryMonster *StrongMonsterFactory::createArtilleryMonster() {
    return new StrongArtilleryEnemy(120,35,30);
}

CloseCombatEnemy *StrongMonsterFactory::createCloseCombatEnemy() {
    return new StrongCloseCombatEnemy(120,40,40);
}
