#include <iostream>

#include "Game.h"


int main() {
    Game juego;
    string input;
    bool correct = false;
    while (!correct) {
        cin >> input;
        correct = true;
        if (input == "init") {
            juego.init();
            juego.run();
        } else if (input == "load") {
            juego.load("partida.txt");
        }

    }


    return 0;
}
