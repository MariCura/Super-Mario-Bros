#include "World.h"
#include "Entity.h"       // aqui si lo necesitamos completo: llamamos a draw y onTouch
#include "Player.h"       // aqui si lo necesitamos completo: lo comparamos por puntero

// Cuantas filas de abajo son el piso de ladrillo.
const int ALTO_PISO = 6;

// Cuantas entidades como maximo. 1 mario + 1 goomba + 3 signos +
// 3 maderas + 3 arbustos + 1 tuberia = 12, con 20 sobrado psright
const int MAX_ENTIDADES = 32;

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

// ---------------------------------------------------------------------------
// Destructor: borra la matriz y el arreglo de punteros.
// OJO: NO hace delete de cada entidad, porque la relacion es AGREGACION.
// Las entidades las borra Game, que es quien las creo.
// ---------------------------------------------------------------------------
World::~World() {
    for (int f = 0; f < filas; f++) {
        delete[] grid[f];
    }
    delete[] grid;
    delete[] entidades;           // solo el arreglo, no lo que apunta
}

// ---------------------------------------------------------------------------
// create_world: deja el mundo limpio. Todo blanco y las ultimas 6 filas
// de piso rojo. Es la funcion create_world() que pide el enunciado.
// ---------------------------------------------------------------------------
void World::create_world() {
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < cols; c++) {
            grid[f][c] = Color::WHITE;      // grid -> atributo de World
        }
    }
    for (int f = filas - ALTO_PISO; f < filas; f++) {
        for (int c = 0; c < cols; c++) {
            grid[f][c] = Color::RED;        // el piso de ladrillo
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

// ---------------------------------------------------------------------------
// collect_coins: revisa que entidades estan chocando con Mario y les
// avisa. Es la funcion collect_coins() que pide el enunciado.
// POLIMORFISMO otra vez: la misma llamada a onTouch da una moneda si es
// un Block de signo, o termina el juego si es el Goomba.
// Saltamos a Mario para que no choque consigo mismo.
// ---------------------------------------------------------------------------
void World::collect_coins(Player& mario) {
    for (int i = 0; i < nEntidades; i++) {
        if (entidades[i] == &mario) {
            continue;                       // Mario no se toca a si mismo
        }
        if (entidades[i]->collides(mario)) {    // collides -> de Entity
            entidades[i]->onTouch(mario);       // onTouch  -> virtual pura de Entity
        }
    }
}

// ---------------------------------------------------------------------------
// add: registra una entidad para dibujarla. La llama Game::init.
// ---------------------------------------------------------------------------
void World::add(Entity* e) {
    if (nEntidades < maxEntidades) {
        entidades[nEntidades] = e;          // entidades -> atributo de World
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
