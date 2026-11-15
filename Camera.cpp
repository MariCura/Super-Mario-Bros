#include "Camera.h"
#include "World.h"        // aqui si lo necesitamos completo: leemos la grilla
#include "Colors.h"       // de aqui viene: imprimirCelda
#include <iostream>

using namespace std;

Camera::Camera(int ancho, int margen) {
    this->ancho  = ancho;     // ancho  -> atributo propio de Camera
    this->margen = margen;    // margen -> atributo propio de Camera
    offset = 0;               // offset -> atributo propio de Camera
}

void Camera::update(int colMario, int anchoMario, int colsMundo) {
    int limite = ancho - anchoMario - margen;   // 36
    int maximo = colsMundo - ancho;             // 150

    offset = colMario - limite;

    if (offset < 0) {
        offset = 0;                             // inicio del mapa
    }
    if (offset > maximo) {
        offset = maximo;                        // final del mapa: la camara se congela
    }
}

void Camera::draw_scene(const World& mundo) const {
    for (int f = 0; f < mundo.getFilas(); f++) {          // getFilas -> de World
        for (int c = offset; c < offset + ancho; c++) {
            imprimirCelda(mundo.getColor(f, c));          // getColor -> de World
        }
        cout << "\n";
    }
}

int Camera::getOffset() const {
    return offset;
}

void Camera::setOffset(int o) {
    offset = o;
}
