#include "Game.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Game::Game() {
    mundo      = nullptr;
    camara     = nullptr;
    mario      = nullptr;
    entidades  = nullptr;
    nEntidades = 0;
    nSignos    = 0;
    corriendo  = false;
    for (int i = 0; i < N_SIGNOS; i++) {
        signos[i] = nullptr;
    }
}

// ---------------------------------------------------------------------------
// Destructor: Game es la clase madre asi que borra lo demás.
// ---------------------------------------------------------------------------
Game::~Game() {
    for (int i = 0; i < nEntidades; i++) {
        delete entidades[i];
    }
    delete[] entidades;
    delete mundo;
    delete camara;
}

// ---------------------------------------------------------------------------
// agregar: guarda la entidad en el arreglo propio (para borrarla despues)
// y se la pasa a World (que solo la referencia: AGREGACION).
// ---------------------------------------------------------------------------
void Game::agregar(Entity* e) {
    if (nEntidades < MAX_ENTIDADES_JUEGO) {
        entidades[nEntidades] = e;
        nEntidades++;
        mundo->add(e);                // add -> metodo de World
    }
}

// ------------------------- FABRICAS DE BLOQUES -----------------------------

// Bloque de signo: lleva sprite normal, sprite quemado y sprite de moneda.
Block* Game::crearSigno(int fila, int col) {
    Sprite* normal  = new Sprite(9, 9, &BLOCK_SIGNO_SPRITE[0][0],  BLOCK_SIGNO_PALETTE, 2);
    Sprite* quemado = new Sprite(9, 9, &BLOCK_SIGNO_QUEMADO[0][0], BLOCK_SIGNO_PALETTE, 2);
    Sprite* moneda  = new Sprite(7, 7, &COIN_SPRITE[0][0],         COIN_PALETTE, 3);
    return new Block(fila, col, normal, true, quemado, moneda);
}

// Bloque de madera: no da moneda, no cambia de dibujo.
Block* Game::crearMadera(int fila, int col) {
    Sprite* normal = new Sprite(9, 9, &BLOCK_MADERA_SPRITE[0][0], BLOCK_MADERA_PALETTE, 2);
    return new Block(fila, col, normal, false);
}

// Arbusto: decoracion, tampoco da moneda.
Block* Game::crearArbusto(int fila, int col) {
    Sprite* normal = new Sprite(7, 8, &TREE_SPRITE[0][0], TREE_PALETTE, 2);
    return new Block(fila, col, normal, false);
}

// Tuberia: decoracion de 12 x 14.
Block* Game::crearTuberia(int fila, int col) {
    Sprite* normal = new Sprite(22, 17, &PIPE_SPRITE[0][0], PIPE_PALETTE, 2);
    return new Block(fila, col, normal, false);
}

// ---------------------------------------------------------------------------
// crearEntidades: el escenario completo repartido en las 240 columnas.
// El piso ocupa las filas 44 a 49, asi que todo lo que va en el suelo
// termina justo en la fila 44 (fila inicial + alto del sprite = 44).
// ---------------------------------------------------------------------------
void Game::crearEntidades() {
    // 03 arbustos (7 de alto): 37 + 7 = 44
    agregar(crearArbusto(37, 40));
    agregar(crearArbusto(37, 100));
    agregar(crearArbusto(37, 180));

    // 01 tuberia (12 de alto): 22 + 22 = 44
    agregar(crearTuberia(22, 150));

    // 03 bloques de madera, a la altura de salto de Mario
    agregar(crearMadera(10, 108));
    agregar(crearMadera(10, 132));
    agregar(crearMadera(10, 188));

    // 03 bloques de signo (los que dan moneda), intercalados con las maderas
    signos[0] = crearSigno(10, 36);
    signos[1] = crearSigno(10, 120);
    signos[2] = crearSigno(10, 200);
    nSignos = N_SIGNOS;
    for (int i = 0; i < N_SIGNOS; i++) {
        agregar(signos[i]);
    }

    // 01 goomba (16 de alto y 16 de ancho): 28 + 16 = 44.
    // Va al final del mapa (columnas 224 a 239) para que Mario pueda recorrer
    // todo el mundo y recoger las 3 monedas antes de chocar con el.
    // Con pasos de 12 columnas, la ultima posicion segura de Mario es la 204.
    agregar(new Goomba(28, 224));

    // Mario va al final para que se dibuje encima de todo lo demas.
    agregar(mario);
}

// ---------------------------------------------------------------------------
// dibujar: los tres pasos de cada frame.
//   1. la camara recalcula con la columna de Mario
//   2. el mundo se repinta completo
//   3. la camara imprime solo las 90 columnas visibles
// ---------------------------------------------------------------------------
void Game::dibujar() {
    camara->update(mario->getCol(), mario->getAncho(), mundo->getCols());
    mundo->draw_world();            // draw_world -> de World
    camara->draw_scene(*mundo);     // draw_scene -> de Camera
}

void Game::init() {

    mundo     = new World(FILAS_MUNDO, COLS_MUNDO);
    camara    = new Camera(ANCHO_ESCENA, MARGEN_CAMARA);
    mario     = new Player(FILA_INICIAL, COL_INICIAL);
    entidades = new Entity*[MAX_ENTIDADES_JUEGO];

    crearEntidades();               // crearEntidades -> metodo de Game
    corriendo = true;

    cout << "$ init" << "\n";
    cout << "$ Welcome to the world of super mario bros xyz" << "\n";
    dibujar();
    cout << "$ Coins = " << mario->getCoins() << "\n";   // getCoins -> de Player
}

void Game::ejecutar(const string& linea) {
    stringstream ss(linea);
    string opcion;

    while (ss >> opcion) {
        bool valido = mario->move_player(opcion, mundo->getFilas(), mundo->getCols());

        if (!valido) {
            cout << "$ invalid operation" << "\n";
            continue;               // no mueve nada y sigue con el siguiente
        }

        if (mario->isEnElAire()) {
            // La recoleccion pasa en el aire, como pide el enunciado.
            mundo->collect_coins(*mario);   // collect_coins -> de World
            dibujar();                      // frame del salto
            mario->caer();                  // caer -> de Player
        }

        mundo->collect_coins(*mario);       // choques ya en el piso

        if (!mario->isVivo()) {             // isVivo -> de Player
            return;
        }
    }
}

void Game::run() {
    string linea;

    while (corriendo) {
        cout << "$ ";
        if (!getline(cin, linea)) {
            break;                   // fin de la entrada
        }
        if (linea.empty()) {
            continue;
        }

        if (linea == "save") {
            save("partida.txt");
            continue;
        }
        if (linea == "load") {
            load("partida.txt");
            dibujar();
            cout << "$ Coins = " << mario->getCoins() << "\n";
            continue;
        }
        if (linea == "exit") {
            break;
        }

        historial.push_back(linea);  // historial -> atributo de Game

        cout << "$ init" << "\n";
        for (size_t i = 0; i < historial.size(); i++) {
            cout << "$ " << historial[i] << "\n";
        }

        ejecutar(linea);             // ejecutar -> metodo de Game
        dibujar();
        cout << "$ Coins = " << mario->getCoins() << "\n";

        if (!mario->isVivo()) {
            cout << "$ Game over" << "\n";
            corriendo = false;
        }
    }
}

void Game::save(const string& archivo) {
    ofstream salida(archivo.c_str());
    if (!salida) {
        cout << "$ no se pudo guardar" << "\n";
        return;
    }

    salida << camara->getOffset() << "\n";                     // getOffset -> de Camera
    salida << mario->getFila() << " " << mario->getCol() << "\n";
    salida << mario->getCoins() << "\n";

    for (int i = 0; i < nSignos; i++) {
        salida << signos[i]->isUsado() << " ";                 // isUsado -> de Block
    }
    salida << "\n";

    salida << historial.size() << "\n";
    for (size_t i = 0; i < historial.size(); i++) {
        salida << historial[i] << "\n";
    }

    salida.close();
    cout << "$ saved" << "\n";
}

void Game::load(const string& archivo) {
    ifstream entrada(archivo.c_str());
    if (!entrada) {
        cout << "$ no se pudo cargar" << "\n";
        return;
    }

    int offset = 0;
    int fila = 0;
    int col = 0;
    int monedas = 0;

    entrada >> offset;
    entrada >> fila >> col;
    entrada >> monedas;

    camara->setOffset(offset);     // setOffset -> de Camera
    mario->setFila(fila);          // setFila   -> heredado de Entity
    mario->setCol(col);            // setCol    -> heredado de Entity
    mario->setCoins(monedas);      // setCoins  -> de Player

    for (int i = 0; i < nSignos; i++) {
        int usado = 0;
        entrada >> usado;
        signos[i]->setUsado(usado == 1);   // setUsado -> de Block
    }

    int cuantos = 0;
    entrada >> cuantos;
    entrada.ignore();              // salta el salto de linea que quedo

    historial.clear();
    string comando;
    for (int i = 0; i < cuantos; i++) {
        if (getline(entrada, comando)) {
            historial.push_back(comando);
        }
    }

    entrada.close();
    cout << "$ loaded" << "\n";
}
