//
// Created by honza on 03.01.2025.
//

#include "MonsterFactory.h"

#include "StrongMonsterFactory.h"
#include "WeakMonsterFactory.h"

MonsterFactory *MonsterFactory::getFactory(TypeOfFactory typeOfFactory) {
    switch (typeOfFactory) {
        case TypeOfFactory::WeakFactory:
            return new WeakMonsterFactory();
        case TypeOfFactory::StrongFactory:
            return new StrongMonsterFactory();
    }
}
