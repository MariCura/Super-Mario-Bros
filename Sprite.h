#ifndef SPRITE_H
#define SPRITE_H

#include "Colors.h"       // de aqui vienen: Color

// ---------------------------------------------------------------------------
// Clase Sprite
// Guarda UN dibujo: la matriz de indices + la paleta de colores.
// Existe para no repetir seis veces el mismo doble for de pintado
// (en el proyecto 1 habia draw_player, draw_goomba, draw_tree, draw_madera,
//  draw_signo y draw_coin, todas iguales salvo el tamano).
//
// Relacion: Entity la contiene por COMPOSICION (Entity la crea y la destruye).
// Memoria dinamica: pixeles y paleta se reservan con new en el constructor.
// ---------------------------------------------------------------------------
class Sprite {
private:
    int    alto;        // numero de filas del dibujo
    int    ancho;       // numero de columnas del dibujo
    int**  pixeles;     // matriz de indices, reservada con new (memoria dinamica)
    Color* paleta;      // arreglo de colores, reservado con new
    int    nColores;    // cuantos colores tiene la paleta

public:
    // datos  -> puntero al primer elemento del sprite, ej: &MARIO_SPRITE[0][0]
    // colores-> puntero al primer elemento de la paleta, ej: MARIO_PALETTE
    Sprite(int alto, int ancho, const int* datos, const Color* colores, int nColores);

    ~Sprite();                       // libera pixeles y paleta

    int   getAlto()  const;          // lo usa Entity::getAlto
    int   getAncho() const;          // lo usa Entity::getAncho
    Color getColor(int i, int j) const;  // color de la celda (i,j); NONE = no pintar
};

#endif
