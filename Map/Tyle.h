//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_TYLE_H
#define DUNGEON_TYLE_H

struct Position{
    int positionX;
    int positionY;
};
enum TyleType {
    TRAP,
    FLOOR
};
class Tyle {
    char m_icon;
    TyleType m_tyleType;
    Position position;
public:
    Position getPosition();
    TyleType getTyleType();
    void setTyleType();
    void setIcon();
    void setPosition();

};


#endif //DUNGEON_TYLE_H
