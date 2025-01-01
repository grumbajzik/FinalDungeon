//
// Created by honza on 01.01.2025.
//

#ifndef EDITPLAYERSKIN_H
#define EDITPLAYERSKIN_H
#include "Button.h"


class EditPlayerSkin : public Button {

    public:

    EditPlayerSkin();

    void execute() override;

    void drawButton() override;
};



#endif //EDITPLAYERSKIN_H
