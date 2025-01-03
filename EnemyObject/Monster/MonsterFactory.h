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
    virtual ArtilleryMonster* createArtilleryMonster() = 0;
    virtual CloseCombatEnemy* createCloseCombatEnemy() = 0;

    public:
    static MonsterFactory* getFactory(TypeOfFactory typeOfFactory);
};



#endif //MONSTERFACTORY_H
