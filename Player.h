#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"       // de aqui viene: Entity (clase base)
#include <string>


class Player : public Entity {
private:
    int  coins;
    bool vivo;
    bool enElAire;
    int filasMundo;
    int colsMundo;

public:
    Player(int fila, int col, int filas, int cols);
    void onTouch(Player&);


    bool operator+=(const std::string& opcion);
    void caer();
    bool isEnElAire() const;

    void addCoin();
    int  getCoins() const;
    void setCoins(int c);

    void matar();
    bool isVivo() const;
};

#endif
