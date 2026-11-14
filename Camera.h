#ifndef CAMERA_H
#define CAMERA_H

class World;              // declaracion adelantada (World.h se incluye en el .cpp)

// ---------------------------------------------------------------------------
// Clase Camera
// Es la pieza nueva de la Parte 2. Solo guarda un numero, el offset, que es
// la primera columna del mundo que se ve en pantalla.
// Gracias a que esta aparte, ninguna otra clase necesita saber que existe
// el desplazamiento: World dibuja las 240 columnas completas y Camera
// decide cuales 90 se imprimen.
// ---------------------------------------------------------------------------
class Camera {
private:
    int offset;       // primera columna visible del mundo (entre 0 y 150)
    int ancho;        // ancho de la escena en celdas (90)
    int margen;       // celdas libres que debe quedar a la derecha de Mario (42)

public:
    Camera(int ancho, int margen);

    // update: recalcula el offset a partir de la columna de Mario.
    //   offset = min( max(colMario - (ancho - anchoMario - margen), 0), colsMundo - ancho )
    // El max resuelve el inicio y el retroceso; el min congela la camara al final.
    void update(int colMario, int anchoMario, int colsMundo);

    // draw_scene: imprime las 50 filas por 90 columnas visibles.
    void draw_scene(const World& mundo) const;

    int  getOffset() const;      // la consulta Game::save
    void setOffset(int o);       // la usa Game::load
};

#endif
