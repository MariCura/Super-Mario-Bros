#include "Block.h"
#include "Player.h"       // aqui si lo necesitamos completo: llamamos a addCoin()
#include "World.h"        // lo necesita pintarSprite

Block::Block(int fila, int col, Sprite* normal, bool daMoneda,
             Sprite* quemado, Sprite* moneda)
    : Entity(fila, col, normal) {
    this->daMoneda = daMoneda;    // daMoneda -> atributo propio de Block
    this->quemado  = quemado;     // quemado  -> atributo propio de Block
    this->moneda   = moneda;      // moneda   -> atributo propio de Block
    usado          = false;
    monedaMostrada = false;
}

Block::~Block() {
    delete quemado;               // quemado -> atributo de Block
    delete moneda;                // moneda  -> atributo de Block
}

// ---------------------------------------------------------------------------
// draw: POLIMORFISMO. Redefine Entity::draw para elegir el sprite.
//   - si todavia no lo golpean  -> sprite normal (heredado de Entity)
//   - si ya lo golpearon        -> sprite quemado
//   - ademas, el primer frame despues del golpe dibuja la moneda arriba
// ---------------------------------------------------------------------------
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
    if (daMoneda && !usado) {     // daMoneda, usado -> atributos de Block
        usado = true;
        mario.addCoin();          // addCoin -> metodo de Player
    }
}

bool Block::isUsado() const {
    return usado;                 // usado -> atributo de Block
}

void Block::setUsado(bool u) {
    usado = u;                    // usado -> atributo de Block
    monedaMostrada = u;           // si se carga como usado, no re-animar la moneda
}

bool Block::getDaMoneda() const {
    return daMoneda;              // daMoneda -> atributo de Block
}
