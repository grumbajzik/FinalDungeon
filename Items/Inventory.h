//
// Created by Micha on 22/01/2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H
#include "Potion.h"
#include <vector>



class Inventory {
    std::vector<Potion*> m_potions;


    public:

    void AddPotion(Potion* potion);
    void RemovePotion(Potion* potion);
    Potion* GetPotion(int index);

};



#endif //INVENTORY_H
