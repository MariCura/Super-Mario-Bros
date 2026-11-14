#include "Goomba.h"
#include "Player.h"       // aqui si lo necesitamos completo: llamamos a matar()
#include "Colors.h"       // de aqui vienen: GOOMBA_SPRITE y GOOMBA_PALETTE

// ---------------------------------------------------------------------------
// Constructor: crea su Sprite de 16x16 y se lo pasa a Entity.
// ---------------------------------------------------------------------------
Goomba::Goomba(int fila, int col)
    : Entity(fila, col, new Sprite(16, 16, &GOOMBA_SPRITE[0][0], GOOMBA_PALETTE, 4)) {
}

// ---------------------------------------------------------------------------
// onTouch: si Mario lo toca, se acaba el juego.
// ---------------------------------------------------------------------------
void Goomba::onTouch(Player& mario) {
    mario.matar();        // matar -> metodo de Player
}
