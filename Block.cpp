#include "Block.h"
#include "Player.h"
#include "World.h"

Block::Block(int fila, int col, Sprite* normal, bool daMoneda,
             Sprite* quemado, Sprite* moneda)
    : Entity(fila, col, normal) {
    this->daMoneda = daMoneda;
    this->quemado  = quemado;
    this->moneda   = moneda;
    usado          = false;
    monedaMostrada = false;
}

Block::~Block() {
    delete quemado;
    delete moneda;
}

// ---------------------------------------------------------------------------
// draw: polimorfismo ps

void Block::draw(World& mundo) {
    if (usado && quemado != nullptr) {
        pintarSprite(mundo, quemado);     // pintarSprite -> heredado de Entity
    }
    else {
        Entity::draw(mundo);              // draw -> version de la clase base
    }

    // La moneda se dibuja una sola vez, justo encima del bloque.
    if (usado && !monedaMostrada && moneda != nullptr) {
        int filaMoneda = fila - moneda->getAlto();   // fila -> heredado de Entity
        int colMoneda  = col + 1;                    // col  -> heredado de Entity
        for (int i = 0; i < moneda->getAlto(); i++) {
            for (int j = 0; j < moneda->getAncho(); j++) {
                mundo.paint(filaMoneda + i, colMoneda + j, moneda->getColor(i, j));
            }
        }
        monedaMostrada = true;
    }
}

void Block::onTouch(Player& mario) {
    if (daMoneda && !usado) {
        usado = true;
        mario.addCoin();          // addCoin -> metodo de Player
    }
}

bool Block::isUsado() const {
    return usado;
}

void Block::setUsado(bool u) {
    usado = u;
    monedaMostrada = u;
}

bool Block::getDaMoneda() const {
    return daMoneda;
}
