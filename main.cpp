
#include <iostream>
#include <fstream>
#include <string>

#include "Game.h"
#include "Player.h"

using namespace std;

int main() {
    Game papita;
    string input;

    ifstream archivo("partida.txt");
    bool existe = archivo.good();
    archivo.close();

    while (true) {
        cout << "===== SUPER MARIO BROS XYZ ====="<< "\n";
        cout << "$ init -> Nueva partida"<< "\n";

        if (existe) {
            cout << "$ load  -> Cargar partida guardada"<<"\n";
        }

        cout << "$ exit  -> Salir del juego"<< "\n";
        cout << "$ ";
        cin >> input;

        if (input == "exit") {
            cout << "$ Hasta pronto..."<< "\n";
            break;
        }

        if (input == "init") {
            papita.init();
            papita.run();
            break;
        }

        if (input == "load" && existe) {
            papita.init();
            papita.load("partida.txt");
            papita.dibujar();
            papita.run();
            break;
        }

        cout << "$ Comando invalido. Intente nuevamente."<<"\n";
    }

    return 0;
}
