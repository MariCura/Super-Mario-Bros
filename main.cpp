#include <iostream>

#include "Game.h"
#include "Player.h"

int main() {
    Game juego;
    string input;

    do {
        cout << "& Ingrese init para empezar el juego"<< "\n";
        cout << "$ "; cin >> input;
    } while (input != "init");
    juego.init();
    juego.run();


    return 0;
}
