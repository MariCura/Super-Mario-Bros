#ifndef SPRITE_H
#define SPRITE_H

#include "Colors.h"       // de aqui vienen: Color
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

#endif
