#ifndef COLORS_H
#define COLORS_H

#include <string>

// ---------------------------------------------------------------------------
// Colors: NO es una clase, es el modulo de constantes del proyecto.
// Guarda el enum Color, los sprites y las paletas.
// Lo usan:  Sprite  (recibe un sprite y una paleta)
//           World   (pinta la grilla con valores Color)
//           Camera  (imprime cada celda con imprimirCelda)
// ---------------------------------------------------------------------------

enum class Color {
    NONE,              // transparente: World::paint lo ignora (no pinta nada)
    BLACK,
    RED,
    GREEN,
    YELLOW,
    WHITE,
    LIGHTRED_EX,
    LIGHTYELLOW_EX,
    LIGHTBLUE_EX,
    LIGHTWHITE_EX
};

// Cada celda del mundo se imprime con este ancho en caracteres.
// Con 2 la escena de 90 columnas ocupa 180 caracteres de ancho.
// Si tu consola es muy grande puedes subirlo a 3 (como en el proyecto 1).
const int ANCHO_CELDA = 1;

// Activa las secuencias ANSI en la consola de Windows.
// En Linux y macOS no hace nada porque ya vienen activadas.
// Se llama una sola vez, desde Game::init().
void habilitarAnsi();

// Devuelve el codigo ANSI de COLOR DE FONDO ("\033[41m" = fondo rojo).
// Usamos fondo + espacios en vez del caracter de bloque porque los
// espacios son ASCII puro y se ven igual en cualquier sistema operativo.
std::string fondo(Color color);

// Imprime una celda ya pintada (fondo de color + espacios + reset).
void imprimirCelda(Color color);

// --------------------------- SPRITES Y PALETAS -----------------------------
// En todas las paletas el indice 0 es Color::NONE = transparente.
// Asi Sprite::getColor devuelve NONE y World::paint simplemente no pinta,
// que es lo que en el proyecto 1 hacia el "if (colorIndex != 0)".
// Las unicas excepciones son la madera y el signo, donde el indice 0 SI
// es el cuerpo del bloque y por eso lleva un color real.

extern const int   MARIO_SPRITE[16][12];
extern const Color MARIO_PALETTE[6];

extern const int   GOOMBA_SPRITE[16][16];
extern const Color GOOMBA_PALETTE[4];

extern const int   TREE_SPRITE[7][8];
extern const Color TREE_PALETTE[2];

extern const int   BLOCK_MADERA_SPRITE[9][9];
extern const Color BLOCK_MADERA_PALETTE[2];

extern const int   BLOCK_SIGNO_SPRITE[9][9];
extern const int   BLOCK_SIGNO_QUEMADO[9][9];
extern const Color BLOCK_SIGNO_PALETTE[2];

extern const int   COIN_SPRITE[7][7];
extern const Color COIN_PALETTE[3];

extern const int   PIPE_SPRITE[22][17];
extern const Color PIPE_PALETTE[2];

#endif
