#include "Game.h"

// ---------------------------------------------------------------------------
// main: lo unico que hace es crear el juego y correrlo.
// Toda la logica esta en las clases.
// Comandos: init (automatico), right, left, up, up-right, up-left,
//           save, load, exit.
// ---------------------------------------------------------------------------
int main() {
    Game juego;        // juego -> objeto de la clase Game

    juego.init();      // init -> metodo de Game: arma el mundo y dibuja la escena
    juego.run();       // run  -> metodo de Game: bucle de comandos

    return 0;
}
