//
// Created by honza on 03.01.2025.
//

#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H
#include "ArtilleryMonster.h"
#include "BossEnemy.h"
#include "CloseCombatEnemy.h"
#include "../../Enums/FactoryType.h"


class MonsterFactory {

    public:

    static MonsterFactory* getFactory(FactoryType typeOfFactory);

    virtual ArtilleryMonster* createArtilleryMonster() = 0;

    virtual CloseCombatEnemy* createCloseCombatEnemy() = 0;

    virtual BossEnemy* createBossEnemy() = 0;
};



#endif //MONSTERFACTORY_H
