#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Game.h"
#include "World.h"
#include "Camera.h"
#include "Player.h"
#include "Goomba.h"
#include "Block.h"
#include "Colors.h"
using namespace std;
// ------------------------- CONSTANTES ----------------------------

const int FILAS_MUNDO    = 50;    // alto del mundo xyz
const int COLS_MUNDO     = 240;   // ancho del mundo xyz
const int ANCHO_ESCENA   = 90;    // columnas que se ven en consola
const int MARGEN_CAMARA  = 42;    // celdas libres a la derecha de Mario
const int FILA_INICIAL   = 28;    // Mario mide 16, 28 + 16 = 44 = borde del piso
const int COL_INICIAL    = 24;
const int MAX_ENTIDADES_JUEGO = 32;
const int N_SIGNOS       = 3;     // Numero de coins p

// ---------------------------------------------------------------------------
// Clase Game
// Es la duena de todo: crea el mundo, la camara, Mario y las entidades,
// corre el bucle de comandos y guarda/carga la partida en archivo.
//
// Relaciones: Game *-- World, Camera, Entity   (COMPOSICION: las crea y borra)
//             World o-- Entity                 (AGREGACION: solo las referencia)
// ---------------------------------------------------------------------------
class Game {
private:
    World*   mundo;                  // COMPOSICION
    Camera*  camara;                 // COMPOSICION
    Player*  mario;                  // COMPOSICION (tambien esta en entidades)
    Entity** entidades;              // todas las entidades, para poder borrarlas
    int      nEntidades;
    Block*   signos[N_SIGNOS];
    int      nSignos;
    bool     corriendo;
    vector<string> historial;   // comandos escritos, para reimprimirlos

    void agregar(Entity* e);         // guarda la entidad y se la pasa a World
    void crearEntidades();           // arma el mundo enterillo
    void dibujar();                  // actualiza la camara + draw_world + draw_scene

    // Fabricas pequenas: cada una crea el Sprite que le toca y devuelve el Block.
    Block* crearSigno(int fila, int col);
    Block* crearMadera(int fila, int col);
    Block* crearArbusto(int fila, int col);
    Block* crearTuberia(int fila, int col);

public:
    Game();
    ~Game();                                  // borra entidades, mundo y camara

    void init();                              // comando "init"
    void run();                               // bucle principal
    void ejecutar(const std::string& linea);  // aplica una linea de movimientos
    void save(const std::string& archivo);    // comando "save"
    void load(const std::string& archivo);    // comando "load"
};

#endif
