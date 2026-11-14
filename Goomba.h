#ifndef GOOMBA_H
#define GOOMBA_H

#include "Entity.h"       // de aqui viene: Entity (clase base)

// ---------------------------------------------------------------------------
// Clase Goomba : public Entity
// El enemigo estatico. No se mueve, solo existe para matar a Mario.
// Es la clase que mejor muestra el POLIMORFISMO: World::collect_coins
// llama a onTouch sin saber si es un Goomba o un Block, y el efecto
// es completamente distinto (aqui mata, alla da una moneda).
// Reemplaza a la funcion Over() del proyecto 1.
// ---------------------------------------------------------------------------
class Goomba : public Entity {
public:
    Goomba(int fila, int col);        // crea su Sprite con GOOMBA_SPRITE
    void onTouch(Player& mario);      // redefine Entity::onTouch -> mata a Mario
};

#endif
