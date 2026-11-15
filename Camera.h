//
// Created by rnap on 8/11/26.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "World.h"

class Camera {
private:
    int offset;       // primera columna visible del mundo (entre 0 y 150)
    int ancho;        // ancho de la escena en celdas (90)
    int margen;       // celdas libres que debe quedar a la derecha de Mario (42)

public:
    Camera(int ancho, int margen);

    void update(int colMario, int anchoMario, int colsMundo);
    void draw_scene(const World& mundo) const;

    int  getOffset() const;
    void setOffset(int o);
};

#endif
