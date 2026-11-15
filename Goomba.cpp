#include "Goomba.h"
#include "Player.h"
#include "Colors.h"

Goomba::Goomba(int fila, int col)
    : Entity(fila, col, new Sprite(16, 16, &GOOMBA_SPRITE[0][0], GOOMBA_PALETTE, 4)) {
}

void Goomba::onTouch(Player& mario) {
    mario.matar();        // matar -> metodo de Player
}
