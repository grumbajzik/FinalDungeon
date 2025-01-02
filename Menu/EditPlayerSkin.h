//
// Created by honza on 01.01.2025.
//

#ifndef EDITPLAYERSKIN_H
#define EDITPLAYERSKIN_H
#include <vector>

#include "Button.h"


class EditPlayerSkin : public Button {

    std::vector<char> m_skins;
    char m_chosenSkin;
    int m_skinIndex = 0;

    public:

    EditPlayerSkin();

    void runEditPlayerSkinMenu();

    void execute() override;

    void drawButton() override;

private:

    void selectSkin(char input);

    void drawMenuWithSkins();
};



#endif //EDITPLAYERSKIN_H
