//
// Created by Micha on 22/01/2025.
//

#include "Inventory.h"

void Inventory::AddPotion(Potion *potion) {
    m_potions.push_back(potion);
}

void Inventory::RemovePotion(Potion *potion) {

}

Potion * Inventory::GetPotion(int index) {
    return m_potions[index];
}
