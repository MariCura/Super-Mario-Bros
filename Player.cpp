#include "Player.h"
#include "Colors.h"

using namespace std;


Player::Player(int fila, int col)
    : Entity(fila, col, new Sprite(16, 12, &MARIO_SPRITE[0][0], MARIO_PALETTE, 6)) {
    coins    = 0;
    vivo     = true;
    enElAire = false;
}

void Player::onTouch(Player&) {
}
bool Player::move_player(const string& opcion, int filasMundo, int colsMundo) {
    int nuevaFila = fila;      // fila -> heredado de Entity
    int nuevaCol  = col;       // col  -> heredado de Entity
    enElAire = false;

    if (opcion == "right") {
        nuevaCol += 12;
    }
    else if (opcion == "left") {
        nuevaCol -= 12;
    }
    else if (opcion == "up") {
        nuevaFila -= 16;
        enElAire = true;
    }
    else if (opcion == "up-right") {
        nuevaCol  += 12;
        nuevaFila -= 16;
        enElAire = true;
    }
    else if (opcion == "up-left") {
        nuevaCol  -= 12;
        nuevaFila -= 16;
        enElAire = true;
    }
    else {
        enElAire = false;
        return false;
    }

    // Revisamos que el rectangulo de Mario entre completo en el mundo.
    if (nuevaFila < 0 || nuevaFila + getAlto() > filasMundo) {   // getAlto -> de Entity
        enElAire = false;
        return false;
    }
    if (nuevaCol < 0 || nuevaCol + getAncho() > colsMundo) {     // getAncho -> de Entity
        enElAire = false;
        return false;
    }

    setFila(nuevaFila);        // setFila -> heredado de Entity
    setCol(nuevaCol);          // setCol  -> heredado de Entity
    return true;
}

void Player::caer() {
    if (enElAire) {
        setFila(fila + 16);
        enElAire = false;
    }
}

bool Player::isEnElAire() const {
    return enElAire;
}

void Player::addCoin() {
    coins++;
}

int Player::getCoins() const {
    return coins;
}

void Player::setCoins(int c) {
    coins = c;
}

void Player::matar() {
    vivo = false;
}

bool Player::isVivo() const {
    return vivo;
}
