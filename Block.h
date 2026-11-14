#ifndef BLOCK_H
#define BLOCK_H

#include "Entity.h"       // de aqui viene: Entity (clase base)

// ---------------------------------------------------------------------------
// Clase Block : public Entity
// Objeto estatico del escenario. Con un solo bool cubre los cuatro casos:
//   signo    -> daMoneda = true,  tiene sprite quemado y sprite de moneda
//   madera   -> daMoneda = false
//   arbusto  -> daMoneda = false
//   tuberia  -> daMoneda = false
//
// Aqui vive el estado que en el proyecto 1 eran tres arreglos globales
// paralelos (bl_check, blrow, blcol), que es justo lo que se desincroniza.
// Reemplaza a touch(), collect_coins(), upcoins() y draw_signal().
// ---------------------------------------------------------------------------
class Block : public Entity {
private:
    bool    daMoneda;       // true solo en los bloques de signo
    bool    usado;          // true despues de que Mario le dio
    bool    monedaMostrada; // para dibujar la moneda una sola vez
    Sprite* quemado;        // sprite negro de despues; puede ser nullptr
    Sprite* moneda;         // sprite de la moneda que sube; puede ser nullptr

public:
    // quemado y moneda solo se pasan en los bloques de signo.
    Block(int fila, int col, Sprite* normal, bool daMoneda = false,
          Sprite* quemado = nullptr, Sprite* moneda = nullptr);

    ~Block();                       // borra quemado y moneda (COMPOSICION)

    void draw(World& mundo);        // redefine Entity::draw -> elige que sprite usar
    void onTouch(Player& mario);    // redefine Entity::onTouch -> suma una moneda

    bool isUsado() const;           // la consulta Game::save
    void setUsado(bool u);          // la usa Game::load
    bool getDaMoneda() const;       // la consulta Game::save para saber a quien guardar
};

#endif
