//
// Created by honza on 23.01.2025.
//

#include "Monster.h"

Monster::Monster() {
}

bool Monster::isItemAfterKill() {
    int value = rand() % 100+1;
    if (value <= 10) {
        return true;
    }
    return false;
}
