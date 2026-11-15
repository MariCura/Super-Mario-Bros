#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"       // de aqui viene: Entity (clase base)
#include <string>


class Player : public Entity {
private:
    int  coins;
    bool vivo;
    bool enElAire;

public:
    Player(int fila, int col);
    void onTouch(Player&);


    bool move_player(const std::string& opcion, int filasMundo, int colsMundo);

    void caer();
    bool isEnElAire() const;

    void addCoin();
    int  getCoins() const;
    void setCoins(int c);

    void matar();
    bool isVivo() const;
};

#endif
