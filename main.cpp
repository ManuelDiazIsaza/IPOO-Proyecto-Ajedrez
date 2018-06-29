/*
  Archivo: main.cpp
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831 - Juan Camargo COD 1741510
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co - camargo.juan@correounivalle.edu.co
  Fecha creacion: 2018-05-14
  Fecha ultima modificacion: 2018-06-25
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad: Main
// Colaboracion: ninguna

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Tablero.h"


using namespace std;

int main()
{

  Tablero tablero;
  //Tablero *tablero1 = new Tablero();

  //Probando jaque mate
  /*tablero.moverFicha("a0 a a4");
    tablero.moverFicha("h0 a a3");
    tablero.moverFicha("e7 a h3");
    tablero.moverFicha("g7 a f5");
  //tablero.moverFicha("f5 a g3");*/

  //Probando Jaque mate (Jaque pastor)
   /* tablero.moverFicha("e1 a e3");
    tablero.moverFicha("e6 a e4");
    tablero.moverFicha("d0 a f2");
    tablero.moverFicha("f0 a c3");
    tablero.moverFicha("f2 a f6");
    tablero.moverFicha("d7 a h3");
    //tablero.moverFicha("a0 a e6");*/

    //tablero.moverFicha("e1 a e3");

    //tablero.guardarPartida();

    //tablero.cargarPartida();
    /*tablero.impTablero();
    tablero.guardarJugada("h7 a h3");
    tablero.guardarJugada("h1 a h2");
    tablero.guardarJugada("a1 a a3");

    tablero.mostrarJugadas();

    tablero.borrarUltimaJugada();

    tablero.mostrarJugadas();*/

    tablero.menuPpal();
    //tablero.menuPpal();

  //Probando Validar movimiento
  //  cout << tablero.validarMovimiento("a6 a a4",1);

  //





  //  tablero.jugar();

    return 0;
}

