#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"

class World;
class Player;

class Entity {
protected:
    int     fila;         // fila superior izquierda dentro del mundo
    int     col;          // columna superior izquierda dentro del mundo
    Sprite* sprite;       // dibujo propio; COMPOSICION, se borra en ~Entity

    // Pinta un sprite cualquiera en el mundo. Es protected para que las
    // clases hijas (Block) puedan reusarla con otro sprite.
    void pintarSprite(World& mundo, Sprite* dibujo);

public:
    Entity(int fila, int col, Sprite* sprite);
    virtual ~Entity();

    virtual void draw(World& mundo);         // POLIMORFISMO: Block la redefine
    virtual void onTouch(Player& mario) = 0; // VIRTUAL PURA: hace a Entity abstracta

    bool colicion(const Entity& otra) const;

    int getFila()  const;
    int getCol()   const;
    int getAlto()  const;                    // sale de sprite->getAlto()
    int getAncho() const;                    // sale de sprite->getAncho()
    void setFila(int f);                     // la usa Player en move_player
    void setCol(int c);                      // la usa Player en move_player
};

#endif
