//
// Created by honza on 03.01.2025.
//

#ifndef WEAKMONSTERFACTORY_H
#define WEAKMONSTERFACTORY_H
#include "MonsterFactory.h"


class WeakMonsterFactory : public MonsterFactory{

    public:
    WeakMonsterFactory();

    ArtilleryMonster *createArtilleryMonster() override;
    CloseCombatEnemy *createCloseCombatEnemy() override;
    BossEnemy* createBossEnemy() override;

};



#endif //WEAKMONSTERFACTORY_H
