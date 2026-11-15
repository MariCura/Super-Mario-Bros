#ifndef WORLD_H
#define WORLD_H
#include "Entity.h"
#include "Player.h"
#include "Colors.h"

class World {
private:
    int      filas;          // 50
    int      cols;           // 240
    Color**  grid;           // matriz de colores, reservada con new
    Entity** entidades;      // arreglo de punteros (AGREGACION), reservado con new
    int      nEntidades;     // cuantas hay guardadas
    int      maxEntidades;   // capacidad del arreglo

public:
    World(int filas, int cols);
    ~World();                               // borra grid y el arreglo, NO las entidades

    void create_world();                    // pinta el fondo blanco y el piso de ladrillo
    void draw_world();                      // create_world + dibuja todas las entidades
    void collect_coins(Player& mario);      // revisa choques y llama a onTouch

    void add(Entity* e);                    // registra una entidad (la llama game::init)
    void paint(int f, int c, Color color);
    Color getColor(int f, int c) const;     // la usa Camera::draw_scene

    int getFilas() const;
    int getCols()  const;
};

#endif
