//
// Created by honza on 03.01.2025.
//

#ifndef WEAKMONSTERFACTORY_H
#define WEAKMONSTERFACTORY_H
#include "MonsterFactory.h"


class WeakMonsterFactory : public MonsterFactory{

    public:

    ArtilleryMonster *createArtilleryMonster() override;
    CloseCombatEnemy *createCloseCombatEnemy() override;

};



#endif //WEAKMONSTERFACTORY_H
