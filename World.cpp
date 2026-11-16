#include "World.h"

const int ALTO_PISO = 6;

const int MAX_ENTIDADES = 30;

// ---------------------------------------------------------------------------
// Constructor: reserva la matriz de colores y el arreglo de punteros.
// ---------------------------------------------------------------------------
World::World(int filas, int cols) {
    this->filas = filas;          // filas -> atributo propio de World
    this->cols  = cols;           // cols  -> atributo propio de World

    // Matriz de colores: arreglo de punteros a filas.
    grid = new Color*[filas];
    for (int f = 0; f < filas; f++) {
        grid[f] = new Color[cols];
    }

    maxEntidades = MAX_ENTIDADES;
    entidades    = new Entity*[maxEntidades];
    nEntidades   = 0;

    create_world();               // create_world -> metodo propio de World
}


World::~World() {
    for (int f = 0; f < filas; f++) {
        delete[] grid[f];
    }
    delete[] grid;
    delete[] entidades;           // solo el arreglo, no lo que apunta
}


void World::create_world() {
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < cols; c++) {
            grid[f][c] = Color::WHITE;      // grid -> atributo de World
        }
    }
    for (int f = filas - ALTO_PISO; f < filas; f++) {
        for (int c = 0; c < cols; c++) {
            if (c < 135 + 29 || 135 + 29 + 17 < c) {
                grid[f][c] = Color::RED;
            } else {
                grid[f][c] = Color::WHITE;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// draw_world: limpia y vuelve a dibujar todas las entidades encima.
// Es la funcion draw_world() que pide el enunciado.
// POLIMORFISMO: llama a draw() sin saber de que clase es cada entidad.
// ---------------------------------------------------------------------------
void World::draw_world() {
    create_world();
    for (int i = 0; i < nEntidades; i++) {
        entidades[i]->draw(*this);          // draw -> virtual de Entity
    }
}


void World::collect_coins(Player& mario) {
    for (int i = 0; i < nEntidades; i++) {
        if (entidades[i] == &mario) {
            continue;                       // Mario no se toca a si mismo
        }
        if (entidades[i]->colicion(mario)) {    // collides -> de Entity
            entidades[i]->onTouch(mario);       // onTouch  -> virtual pura de Entity
        }
    }
}

void World::add(Entity* e) {
    if (nEntidades < maxEntidades) {
        entidades[nEntidades] = e;
        nEntidades++;
    }
}

// ---------------------------------------------------------------------------
// paint: pinta una celda. Hace las dos verificaciones que en el proyecto 1
// estaban repetidas en las seis funciones de dibujo:
//   - que la celda este dentro del mundo
//   - que el color no sea transparente
// ---------------------------------------------------------------------------
void World::paint(int f, int c, Color color) {
    if (color == Color::NONE) {
        return;                             // transparente: no se pinta
    }
    if (f < 0 || f >= filas || c < 0 || c >= cols) {
        return;                             // fuera del mundo: no se pinta
    }
    grid[f][c] = color;                     // grid -> atributo de World
}

Color World::getColor(int f, int c) const {
    if (f < 0 || f >= filas || c < 0 || c >= cols) {
        return Color::WHITE;
    }
    return grid[f][c];                      // grid -> atributo de World
}

int World::getFilas() const {
    return filas;                           // filas -> atributo de World
}

int World::getCols() const {
    return cols;                            // cols -> atributo de World
}
