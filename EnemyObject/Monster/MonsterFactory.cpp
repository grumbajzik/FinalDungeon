//
// Created by honza on 03.01.2025.
//

#include "MonsterFactory.h"

#include "StrongMonsterFactory.h"
#include "WeakMonsterFactory.h"

MonsterFactory *MonsterFactory::getFactory(FactoryType typeOfFactory) {
    switch (typeOfFactory) {
        case FactoryType::WeakFactory:
            return new WeakMonsterFactory();
        case FactoryType::StrongFactory:
            return new StrongMonsterFactory();
        default:
            return nullptr;
    }
}
