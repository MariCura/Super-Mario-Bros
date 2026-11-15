#ifndef COLORS_H
#define COLORS_H

#include <string>

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


const int ANCHO_CELDA = 1;

std::string fondo(Color color);


void imprimirCelda(Color color);

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
