#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"       // de aqui viene: Entity (clase base)
#include <string>

// ---------------------------------------------------------------------------
// Clase Player : public Entity   -> Mario
// Es la unica entidad que se mueve y que guarda estado (monedas, vivo).
// Hereda de Entity: fila, col, sprite, draw, collides.
// ---------------------------------------------------------------------------
class Player : public Entity {
private:
    int  coins;           // monedas recogidas (antes era la global "coins")
    bool vivo;            // false cuando el goomba lo toca
    bool enElAire;        // true justo despues de un salto, hasta que cae

public:
    Player(int fila, int col);        // crea su propio Sprite con MARIO_SPRITE
    void onTouch(Player&);            // redefine Entity::onTouch (Mario no se toca solo)

    // move_player: aplica el movimiento solo si cabe dentro del mundo.
    // Devuelve false si el movimiento es invalido (no lo aplica).
    bool move_player(const std::string& opcion, int filasMundo, int colsMundo);

    void caer();                      // baja las 16 filas del salto
    bool isEnElAire() const;          // la consulta Game::ejecutar

    void addCoin();                   // la llama Block::onTouch
    int  getCoins() const;            // la consulta Game para imprimir "$ Coins = n"
    void setCoins(int c);             // la usa Game::load

    void matar();                     // la llama Goomba::onTouch
    bool isVivo() const;              // la consulta Game::run
};

#endif
