#include "Colors.h"
#include <iostream>



using namespace std;



// ---------------------------------------------------------------------------
// fondo: traduce un Color del enum al codigo ANSI de color de fondo.
// ---------------------------------------------------------------------------
string fondo(Color color) {
    switch (color) {
        case Color::BLACK:           return "\033[40m";
        case Color::RED:             return "\033[41m";
        case Color::GREEN:           return "\033[42m";
        case Color::YELLOW:          return "\033[43m";
        case Color::WHITE:           return "\033[47m";
        case Color::LIGHTRED_EX:     return "\033[101m";
        case Color::LIGHTYELLOW_EX:  return "\033[103m";
        case Color::LIGHTBLUE_EX:    return "\033[104m";
        case Color::LIGHTWHITE_EX:   return "\033[107m";
        default:                     return "\033[47m";   // NONE se ve blanco
    }
}

// ---------------------------------------------------------------------------
// imprimirCelda: fondo de color + espacios + reset.
// La llama Camera::draw_scene una vez por celda visible.
// ---------------------------------------------------------------------------
void imprimirCelda(Color color) {
    cout << fondo(color);
    for (int i = 0; i < ANCHO_CELDA; i++) {
        cout << "   ";
    }
    cout << "\033[0m";
}

// --------------------------- SPRITES Y PALETAS -----------------------------

// Mario: 16 filas x 12 columnas
const int MARIO_SPRITE[16][12] = {
    {0,0,0,1,1,1,1,1,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,0},
    {0,0,2,2,2,3,3,2,3,0,0,0},
    {0,2,3,2,3,3,3,2,3,3,3,0},
    {0,2,3,2,2,3,3,3,2,3,3,3},
    {0,2,2,3,3,3,3,2,2,2,2,0},
    {0,0,0,3,3,3,3,3,3,3,0,0},
    {0,0,1,1,4,1,1,4,1,1,0,0},
    {0,1,1,1,4,1,1,4,1,1,1,0},
    {1,1,1,1,4,4,4,4,1,1,1,1},
    {3,3,1,4,5,4,4,5,1,1,3,3},
    {3,3,3,4,4,4,4,4,4,3,3,3},
    {3,3,4,4,4,4,4,4,4,4,3,3},
    {0,0,4,4,4,0,0,4,4,4,0,0},
    {0,0,2,2,0,0,0,0,2,2,0,0},
    {0,2,2,2,0,0,0,0,2,2,2,0}
};
const Color MARIO_PALETTE[6] = {
    Color::NONE,              // 0 = transparente
    Color::LIGHTRED_EX,
    Color::BLACK,
    Color::LIGHTWHITE_EX,
    Color::LIGHTBLUE_EX,
    Color::LIGHTYELLOW_EX
};

// Goomba: 16 filas x 16 columnas
const int GOOMBA_SPRITE[16][16] = {
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,2,2,1,1,1,1,1,1,2,2,1,0,0},
    {0,1,1,1,3,2,1,1,1,1,2,3,1,1,1,0},
    {0,1,1,1,3,2,2,2,2,2,2,3,1,1,1,0},
    {1,1,1,1,3,2,3,1,1,3,2,3,1,1,1,1},
    {1,1,1,1,3,3,3,1,1,3,3,3,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,3,3,3,3,3,3,1,1,1,1,0},
    {0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0},
    {0,0,0,2,3,3,3,3,3,3,3,3,2,0,0,0},
    {0,0,2,2,2,2,3,3,3,3,2,2,2,2,0,0},
    {0,0,2,2,2,2,2,0,0,2,2,2,2,2,0,0},
    {0,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0}
};
const Color GOOMBA_PALETTE[4] = {
    Color::NONE,              // 0 = transparente
    Color::YELLOW,
    Color::BLACK,
    Color::LIGHTWHITE_EX
};

// Arbusto (arbol pequeno): 7 filas x 8 columnas
const int TREE_SPRITE[7][8] = {
    {0,0,0,1,1,0,0,0},
    {0,0,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1}
};
const Color TREE_PALETTE[2] = {
    Color::NONE,              // 0 = transparente
    Color::GREEN
};

// Bloque de madera: 9 filas x 9 columnas
// Aqui el indice 0 SI se pinta: es el cuerpo rojo del bloque.
const int BLOCK_MADERA_SPRITE[9][9] = {
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0},
    {1,1,1,1,1,1,1,1,1},
    {0,0,1,0,0,0,1,0,0},
    {0,0,1,0,0,0,1,0,0},
    {0,0,1,0,0,0,1,0,0},
    {1,1,1,1,1,1,1,1,1},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0}
};
const Color BLOCK_MADERA_PALETTE[2] = {
    Color::RED,               // 0 = cuerpo del bloque (NO transparente)
    Color::BLACK
};

// Bloque de signo (lucky block): 9 filas x 9 columnas
// Igual que la madera, el indice 0 es el cuerpo amarillo.
const int BLOCK_SIGNO_SPRITE[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0},
    {0,0,1,0,0,0,1,0,0},
    {0,0,0,0,0,1,1,0,0},
    {0,0,0,0,0,1,1,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};
// El mismo bloque despues de darle: todo negro (quemado).
const int BLOCK_SIGNO_QUEMADO[9][9] = {
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1}
};
const Color BLOCK_SIGNO_PALETTE[2] = {
    Color::LIGHTYELLOW_EX,    // 0 = cuerpo del bloque (NO transparente)
    Color::BLACK
};

// Moneda: 7 filas x 7 columnas
const int COIN_SPRITE[7][7] = {
    {0,0,1,1,1,0,0},
    {0,1,1,1,1,1,0},
    {1,1,1,2,1,1,1},
    {1,1,1,2,1,1,1},
    {1,1,1,2,1,1,1},
    {0,1,1,2,1,1,0},
    {0,0,1,1,1,0,0}
};
const Color COIN_PALETTE[3] = {
    Color::NONE,              // 0 = transparente
    Color::YELLOW,
    Color::BLACK
};

// Tuberia: 12 filas x 14 columnas (boca ancha arriba, cuerpo angosto abajo)
const int PIPE_SPRITE[22][17] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},

};
const Color PIPE_PALETTE[2] = {
    Color::NONE,              // 0 = transparente
    Color::GREEN
};
