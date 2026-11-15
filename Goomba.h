#ifndef GOOMBA_H
#define GOOMBA_H

#include "Entity.h"


class Goomba : public Entity {
public:
    Goomba(int fila, int col);        // crea su Sprite con GOOMBA_SPRITE
    void onTouch(Player& mario);      // redefine Entity::onTouch -> mata a Mario
};

#endif
