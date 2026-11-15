#include "Sprite.h"

// ---------------------------------------------------------------------------
// Constructor: copia el sprite y la paleta a memoria dinamica.
// ---------------------------------------------------------------------------
Sprite::Sprite(int alto, int ancho, const int* datos, const Color* colores, int nColores) {
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
Sprite::~Sprite() {
    for (int i = 0; i < alto; i++) {
        delete[] pixeles[i];          // primero cada fila
    }
    delete[] pixeles;                 // luego el arreglo de punteros
    delete[] paleta;                  // y por ultimo la paleta
}

int Sprite::getAlto() const {
    return alto;                      // alto -> atributo de Sprite
}

int Sprite::getAncho() const {
    return ancho;                     // ancho -> atributo de Sprite
}

Color Sprite::getColor(int i, int j) const {
    if (i < 0 || i >= alto || j < 0 || j >= ancho) {
        return Color::NONE;
    }
    int indice = pixeles[i][j];       // pixeles -> atributo de Sprite
    if (indice < 0 || indice >= nColores) {
        return Color::NONE;
    }
    return paleta[indice];            // paleta -> atributo de Sprite
}
