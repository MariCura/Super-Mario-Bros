#ifndef BLOCK_H
#define BLOCK_H

#include "Entity.h"       // de aqui viene: Entity (clase base)

class Block : public Entity {
private:
    bool    daMoneda;
    bool    usado;
    bool    monedaMostrada;
    Sprite* quemado;
    Sprite* moneda;

public:

    Block(int fila, int col, Sprite* normal, bool daMoneda = false,
          Sprite* quemado = nullptr, Sprite* moneda = nullptr);

    ~Block();

    void draw(World& mundo);
    void onTouch(Player& mario);

    bool isUsado() const;
    void setUsado(bool u);
    bool getDaMoneda() const;
};

#endif
