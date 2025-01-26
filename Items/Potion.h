//
// Created by Micha on 22/01/2025.
//

#ifndef POTION_H
#define POTION_H





class Potion {

    public:

    static Potion *createPotion();
    virtual void usePotion() = 0;
    virtual void cancelBonus() = 0;

private:

    int getRandomIndex();

};



#endif //POTION_H
