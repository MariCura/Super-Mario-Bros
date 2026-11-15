#include "Entity.h"
#include "World.h"

Entity::Entity(int fila, int col, Sprite* sprite) {
    this->fila   = fila;
    this->col    = col;
    this->sprite = sprite;
}


Entity::~Entity() {
    delete sprite;
}

void Entity::pintarSprite(World& mundo, Sprite* dibujo) {
    for (int i = 0; i < dibujo->getAlto(); i++) {          // getAlto  -> de Sprite
        for (int j = 0; j < dibujo->getAncho(); j++) {     // getAncho -> de Sprite
            Color c = dibujo->getColor(i, j);              // getColor -> de Sprite
            mundo.paint(fila + i, col + j, c);             // paint    -> de World
        }
    }
}

void Entity::draw(World& mundo) {
    pintarSprite(mundo, sprite);   // pintarSprite -> metodo propio de Entity
}

bool Entity::collides(const Entity& otra) const {
    bool cruzanFilas = (fila < otra.fila + otra.getAlto()) &&
                       (otra.fila < fila + getAlto());

    bool cruzanCols  = (col < otra.col + otra.getAncho()) &&
                       (otra.col < col + getAncho());

    return cruzanFilas && cruzanCols;
}

int Entity::getFila() const {
    return fila;
}

int Entity::getCol() const {
    return col;
}

int Entity::getAlto() const {
    return sprite->getAlto();
}

int Entity::getAncho() const {
    return sprite->getAncho();
}

void Entity::setFila(int f) {
    fila = f;
}

void Entity::setCol(int c) {
    col = c;
}
