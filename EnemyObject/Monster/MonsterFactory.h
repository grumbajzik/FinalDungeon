//
// Created by honza on 03.01.2025.
//

#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H
#include "ArtilleryMonster.h"
#include "CloseCombatEnemy.h"

enum TypeOfFactory {
    WeakFactory,
    StrongFactory
};


class MonsterFactory {

    public:

    static MonsterFactory* getFactory(TypeOfFactory typeOfFactory);

    virtual ArtilleryMonster* createArtilleryMonster() = 0;

    virtual CloseCombatEnemy* createCloseCombatEnemy() = 0;
};



#endif //MONSTERFACTORY_H
