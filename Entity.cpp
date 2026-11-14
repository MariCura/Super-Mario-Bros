#include "Entity.h"
#include "World.h"        // aqui si lo necesitamos completo: usamos World::paint

// ---------------------------------------------------------------------------
// Constructor: guarda la posicion y toma posesion del sprite.
// ---------------------------------------------------------------------------
Entity::Entity(int fila, int col, Sprite* sprite) {
    this->fila   = fila;        // fila   -> atributo de Entity
    this->col    = col;         // col    -> atributo de Entity
    this->sprite = sprite;      // sprite -> atributo de Entity (COMPOSICION)
}

// ---------------------------------------------------------------------------
// Destructor: como Entity es dueno del sprite, lo borra.
// Es virtual para que al hacer delete sobre un Entity* se llame al
// destructor de la clase hija correcta (Player, Goomba o Block).
// ---------------------------------------------------------------------------
Entity::~Entity() {
    delete sprite;              // sprite -> atributo de Entity
}

// ---------------------------------------------------------------------------
// pintarSprite: el unico doble for de pintado de todo el proyecto.
// Recorre el dibujo y le pide a World que pinte celda por celda.
// Las celdas con Color::NONE no se pintan (las ignora World::paint).
// ---------------------------------------------------------------------------
void Entity::pintarSprite(World& mundo, Sprite* dibujo) {
    for (int i = 0; i < dibujo->getAlto(); i++) {          // getAlto  -> de Sprite
        for (int j = 0; j < dibujo->getAncho(); j++) {     // getAncho -> de Sprite
            Color c = dibujo->getColor(i, j);              // getColor -> de Sprite
            mundo.paint(fila + i, col + j, c);             // paint    -> de World
        }
    }
}

// ---------------------------------------------------------------------------
// draw: version por defecto, dibuja el sprite propio.
// Player y Goomba la usan tal cual; Block la redefine (POLIMORFISMO).
// ---------------------------------------------------------------------------
void Entity::draw(World& mundo) {
    pintarSprite(mundo, sprite);   // pintarSprite -> metodo propio de Entity
}

// ---------------------------------------------------------------------------
// collides: choque entre dos rectangulos.
// Se cruzan si se cruzan en filas Y se cruzan en columnas.
// Reemplaza a la funcion touch() del proyecto 1, pero sirve para cualquier
// par de entidades, no solo para los tres bloques.
// ---------------------------------------------------------------------------
bool Entity::collides(const Entity& otra) const {
    bool cruzanFilas = (fila < otra.fila + otra.getAlto()) &&
                       (otra.fila < fila + getAlto());

    bool cruzanCols  = (col < otra.col + otra.getAncho()) &&
                       (otra.col < col + getAncho());

    return cruzanFilas && cruzanCols;
}

int Entity::getFila() const {
    return fila;                   // fila -> atributo de Entity
}

int Entity::getCol() const {
    return col;                    // col -> atributo de Entity
}

int Entity::getAlto() const {
    return sprite->getAlto();      // getAlto -> de Sprite
}

int Entity::getAncho() const {
    return sprite->getAncho();     // getAncho -> de Sprite
}

void Entity::setFila(int f) {
    fila = f;                      // fila -> atributo de Entity
}

void Entity::setCol(int c) {
    col = c;                       // col -> atributo de Entity
}
