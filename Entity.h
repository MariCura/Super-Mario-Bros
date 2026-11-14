#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"       // de aqui viene: Sprite
#include "World.h"
#include "Player.h"


// ---------------------------------------------------------------------------
// Clase Entity  (ABSTRACTA)  -> aqui viven la HERENCIA y el POLIMORFISMO
// Todo lo que se dibuja en el mundo tiene fila, columna y un sprite.
// Lo unico que cambia entre Mario, el goomba y los bloques es:
//   - que pasa cuando Mario los toca  -> onTouch (virtual pura)
//   - que sprite se dibuja            -> draw (virtual, Block la redefine)
//
// Relaciones: Entity *-- Sprite      (composicion: la crea y la destruye)
//             World  o-- Entity      (agregacion: World solo guarda punteros)
// ---------------------------------------------------------------------------
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
    virtual ~Entity();                       // virtual: se borra bien por puntero base

    virtual void draw(World& mundo);         // POLIMORFISMO: Block la redefine
    virtual void onTouch(Player& mario) = 0; // VIRTUAL PURA: hace a Entity abstracta

    bool collides(const Entity& otra) const; // choque de dos rectangulos

    int getFila()  const;                    // fila   -> atributo de Entity
    int getCol()   const;                    // col    -> atributo de Entity
    int getAlto()  const;                    // sale de sprite->getAlto()
    int getAncho() const;                    // sale de sprite->getAncho()
    void setFila(int f);                     // la usa Player::move_player
    void setCol(int c);                      // la usa Player::move_player
};

#endif
