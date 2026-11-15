//
// Created by rnap on 15/11/26.
//

#ifndef SUPERMARIOBROSXYZ_COLOR_H
#define SUPERMARIOBROSXYZ_COLOR_H

#include <iostream>
#include <string>

// ------------------------------- COLORES -------------------------------

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

// Codigo ANSI de color de FONDO para cada Color.
inline std::string fondo(Color color) {
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

// Imprime una celda: color de fondo + espacios + reset.
inline void imprimirCelda(Color color) {
    std::cout << fondo(color);
    for (int i = 0; i < ANCHO_CELDA; i++) {
        std::cout << "   ";
    }
    std::cout << "\033[0m";
}

// --------------------------- SPRITES Y PALETAS -------------------------

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
    Color::NONE,
    Color::LIGHTRED_EX,
    Color::BLACK,
    Color::LIGHTWHITE_EX,
    Color::LIGHTBLUE_EX,
    Color::LIGHTYELLOW_EX
};


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
    Color::NONE,
    Color::YELLOW,
    Color::BLACK,
    Color::LIGHTWHITE_EX
};


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
    Color::NONE,
    Color::GREEN
};


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
    Color::RED,
    Color::BLACK
};


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
    Color::LIGHTYELLOW_EX,
    Color::BLACK
};


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
    Color::NONE,
    Color::YELLOW,
    Color::BLACK
};


// Tuberia: 22 filas x 17 columnas (5 filas de boca + 17 de cuerpo)
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
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0}
};
const Color PIPE_PALETTE[2] = {
    Color::NONE,
    Color::GREEN
};


// ------------------------------- SPRITE --------------------------------

class Sprite {
private:
    int    alto;
    int    ancho;
    int**  pixeles;
    Color* paleta;
    int    nColores;

public:
    Sprite(int alto, int ancho, const int* datos, const Color* colores, int nColores);

    ~Sprite();                       // libera pixeles y paleta

    int   getAlto()  const;          // lo usa Entity::getAlto
    int   getAncho() const;          // lo usa Entity::getAncho
    Color getColor(int i, int j) const;  // color de la celda (i,j); NONE = no pintar
};

// ---------------------------------------------------------------------------
// Constructor: copia el sprite y la paleta a memoria dinamica.
// ---------------------------------------------------------------------------
inline Sprite::Sprite(int alto, int ancho, const int* datos, const Color* colores, int nColores) {
    this->alto     = alto;            // alto  -> atributo propio de Sprite
    this->ancho    = ancho;           // ancho -> atributo propio de Sprite
    this->nColores = nColores;        // nColores -> atributo propio de Sprite

    // Reservamos la matriz de pixeles: un arreglo de punteros a filas.
    pixeles = new int*[alto];
    for (int i = 0; i < alto; i++) {
        pixeles[i] = new int[ancho];
        for (int j = 0; j < ancho; j++) {
            // datos viene aplanado, por eso el indice es i*ancho + j
            pixeles[i][j] = datos[i * ancho + j];
        }
    }

    // Reservamos y copiamos la paleta.
    paleta = new Color[nColores];
    for (int k = 0; k < nColores; k++) {
        paleta[k] = colores[k];
    }
}

// ---------------------------------------------------------------------------
// Destructor: libera en orden inverso a como se reservo.
// ---------------------------------------------------------------------------
inline Sprite::~Sprite() {
    for (int i = 0; i < alto; i++) {
        delete[] pixeles[i];          // primero cada fila
    }
    delete[] pixeles;                 // luego el arreglo de punteros
    delete[] paleta;                  // y por ultimo la paleta
}

inline int Sprite::getAlto() const {
    return alto;                      // alto -> atributo de Sprite
}

inline int Sprite::getAncho() const {
    return ancho;                     // ancho -> atributo de Sprite
}

inline Color Sprite::getColor(int i, int j) const {
    if (i < 0 || i >= alto || j < 0 || j >= ancho) {
        return Color::NONE;
    }
    int indice = pixeles[i][j];       // pixeles -> atributo de Sprite
    if (indice < 0 || indice >= nColores) {
        return Color::NONE;
    }
    return paleta[indice];            // paleta -> atributo de Sprite
}

// -----------------------------------------

#endif //SUPERMARIOBROSXYZ_COLOR_H
