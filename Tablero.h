

#ifndef _TABLERO_
#define _TABLERO_

#include <string>
#include <iostream>
#include "Fichas.h"

using namespace std;


class Tablero{
private:
    Fichas tablero[8][8];
    int xBlanco = 4;
    int yBlanco = 7;
    int xNegro = 4;
    int yNegro = 0;

public:
    Tablero();
    ~Tablero();

    // set and get
    void setXnegro(int xnegro);
    int getXnegro();
    void setYnegro(int ynegro);
    int getYnegro();
    void setXblanco(int xblanco);
    int getXblanco();
    void setYblanco(int yblanco);
    int getYblanco();
    
    void impTablero();
    bool veriMov(string mov);
    void moverFicha(string mov);
    void devolverFicha(string mov);
    bool validarMovimiento(string mov, int jugador);
    bool estoyEnJaque(int jugadorA, int opci);
    void jugar();
};

#endif