//
// Created by honza on 21.01.2025.
//

#ifndef SKILLS_H
#define SKILLS_H
#include "../Player.h"


class Skills {

    public:

    Skills();

    virtual void learnSkill(Player* player) = 0;

};



#endif //SKILLS_H
