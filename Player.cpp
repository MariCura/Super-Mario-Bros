#include "Player.h"
#include "Colors.h"       // de aqui vienen: MARIO_SPRITE y MARIO_PALETTE

using namespace std;

// Pasos de movimiento que pide el enunciado.
const int PASO_HORIZONTAL = 12;   // right y left mueven 12 columnas
const int PASO_VERTICAL   = 16;   // up sube 16 filas

// ---------------------------------------------------------------------------
// Constructor: crea su Sprite y se lo entrega a Entity (clase base).
// &MARIO_SPRITE[0][0] es el primer elemento, porque Sprite recibe el
// sprite aplanado.
// ---------------------------------------------------------------------------
Player::Player(int fila, int col)
    : Entity(fila, col, new Sprite(16, 12, &MARIO_SPRITE[0][0], MARIO_PALETTE, 6)) {
    coins    = 0;          // coins    -> atributo propio de Player
    vivo     = true;       // vivo     -> atributo propio de Player
    enElAire = false;      // enElAire -> atributo propio de Player
}

// Mario no se toca a si mismo, pero onTouch es virtual pura en Entity
// asi que hay que darle un cuerpo (vacio) para que Player se pueda crear.
// El parametro va sin nombre porque no se usa.
void Player::onTouch(Player&) {
}

// ---------------------------------------------------------------------------
// move_player: calcula la posicion nueva, revisa que quepa y recien ahi
// la aplica. Si no cabe no mueve nada y devuelve false, para que Game
// imprima "invalid operation" sin terminar el juego.
// ---------------------------------------------------------------------------
bool Player::move_player(const string& opcion, int filasMundo, int colsMundo) {
    int nuevaFila = fila;      // fila -> heredado de Entity
    int nuevaCol  = col;       // col  -> heredado de Entity
    enElAire = false;

    if (opcion == "right") {
        nuevaCol += PASO_HORIZONTAL;
    }
    else if (opcion == "left") {
        nuevaCol -= PASO_HORIZONTAL;
    }
    else if (opcion == "up") {
        nuevaFila -= PASO_VERTICAL;
        enElAire = true;
    }
    else if (opcion == "up-right") {
        nuevaCol  += PASO_HORIZONTAL;
        nuevaFila -= PASO_VERTICAL;
        enElAire = true;
    }
    else if (opcion == "up-left") {
        nuevaCol  -= PASO_HORIZONTAL;
        nuevaFila -= PASO_VERTICAL;
        enElAire = true;
    }
    else {
        enElAire = false;
        return false;          // comando que no existe
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

// ---------------------------------------------------------------------------
// caer: despues de dibujar el salto, Mario vuelve a su fila de abajo.
// El movimiento horizontal del salto diagonal si se queda.
// ---------------------------------------------------------------------------
void Player::caer() {
    if (enElAire) {
        setFila(fila + PASO_VERTICAL);   // setFila -> heredado de Entity
        enElAire = false;
    }
}

bool Player::isEnElAire() const {
    return enElAire;           // enElAire -> atributo de Player
}

void Player::addCoin() {
    coins++;                   // coins -> atributo de Player
}

int Player::getCoins() const {
    return coins;              // coins -> atributo de Player
}

void Player::setCoins(int c) {
    coins = c;                 // coins -> atributo de Player
}

void Player::matar() {
    vivo = false;              // vivo -> atributo de Player
}

bool Player::isVivo() const {
    return vivo;               // vivo -> atributo de Player
}
