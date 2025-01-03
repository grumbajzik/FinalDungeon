//
// Created by honza on 03.01.2025.
//

#ifndef DIFFICULTYOFGAMEBUTTON_H
#define DIFFICULTYOFGAMEBUTTON_H
#include <vector>

#include "Button.h"
#include "../EnemyObject/Monster/MonsterFactory.h"


class DifficultyOfGameButton : public Button {

    std::vector<std::string> m_difficulty;
    int m_index;

    public:

    DifficultyOfGameButton();

    void drawButton() override;

    void execute() override;

    void runDifficultyOfGameMenu();

private:

    void drawDifficultyOfGameButton();

    void getTypeOfFactory();

    void selectDifficulty(char input);
};



#endif //DIFFICULTYOFGAMEBUTTON_H
