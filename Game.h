//
// Created by rnap on 8/11/26.
//

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "World.h"
#include "Camera.h"
#include "Player.h"
#include "Goomba.h"
#include "Block.h"
#include "Color.h"
using namespace std;
// ------------------------- CONSTANTES ----------------------------

const int FILAS_MUNDO    = 50;
const int COLS_MUNDO     = 240;
const int ANCHO_ESCENA   = 90;
const int MARGEN_CAMARA  = 42;
const int FILA_INICIAL   = 28;
const int COL_INICIAL    = 1;
const int MAX_ENTIDADES_JUEGO = 32;
const int N_SIGNOS       = 6;     // Numero de coins p

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
    Entity** entidades;              // todas las entidades, para poder borrarlas p
    int      nEntidades;
    Block*   signos[N_SIGNOS];
    int      nSignos;
    bool     corriendo;
    vector<string> historial;   // historial de comandos

    void agregar(Entity* e);         // guarda la entidad y se la pasa a World
    void crearEntidades();           // arma el mundo enterillo



    Block* crearSigno(int fila, int col);
    Block* crearMadera(int fila, int col);
    Block* crearArbusto(int fila, int col);
    Block* crearTuberia(int fila, int col);

public:
    Game();
    ~Game();
    void dibujar();

    void init();
    void run();
    void ejecutar(const std::string& linea);
    void save(const std::string& archivo);
    void load(const std::string& archivo);
};

#endif
