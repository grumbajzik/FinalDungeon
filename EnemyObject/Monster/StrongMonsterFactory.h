//
// Created by honza on 03.01.2025.
//

#ifndef STRONGMONSTERFACTORY_H
#define STRONGMONSTERFACTORY_H
#include "MonsterFactory.h"


class StrongMonsterFactory : public MonsterFactory{

    public:

    StrongMonsterFactory();

    ArtilleryMonster *createArtilleryMonster() override;
    CloseCombatEnemy *createCloseCombatEnemy() override;

};



#endif //STRONGMONSTERFACTORY_H
