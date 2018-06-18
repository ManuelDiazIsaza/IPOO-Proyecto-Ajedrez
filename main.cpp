/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Tablero.h"


using namespace std;

int main()
{

  Tablero tablero;

 // tablero.impTablero();
 // cout << tablero.veriMov("b7 a c2");
  //tablero.moverFicha("b6 a b4");

/*  tablero.moverFicha("b6 a b5");
  tablero.moverFicha("b0 a c4");
  tablero.moverFicha("c4 a d6");
  tablero.moverFicha("a6 a d1");
  tablero.moverFicha("a7 a b4");
  tablero.moverFicha("b5 a a5");
  tablero.moverFicha("b4 a b2");
  tablero.moverFicha("a5 a b6");
  tablero.moverFicha("d1 a d2");
  tablero.moverFicha("b2 a c3");
  tablero.moverFicha("b1 a b3");
  tablero.moverFicha("c6 a c4");
  tablero.moverFicha("d2 a d3");
  tablero.moverFicha("c7 a b2");
  tablero.moverFicha("c7 a d4");
  tablero.moverFicha("b2 a d4");
  tablero.moverFicha("d4 a d2");
  tablero.moverFicha("b7 a f3");
  tablero.moverFicha("b3 a b4");
  tablero.moverFicha("b4 a b5");
  tablero.moverFicha("e6 a e5");
  tablero.moverFicha("d3 a e4");
  tablero.moverFicha("f1 a f4");
  tablero.moverFicha("c4 a d4");
  tablero.moverFicha("c1 a d3");
  tablero.moverFicha("c3 a a3");
  tablero.moverFicha("e0 a d1");
  tablero.moverFicha("d1 a c2");
  tablero.moverFicha("e7 a e6");
  tablero.moverFicha("e6 a d5");
  tablero.moverFicha("d5 a h4");
  tablero.moverFicha("d0 a e0");
  tablero.moverFicha("f0 a e0");
  tablero.moverFicha("c2 a c3");
  tablero.moverFicha("d2 a c2");
  tablero.moverFicha("c3 a a4");
  tablero.moverFicha("c2 a e1");
  tablero.moverFicha("h4 a h3");
  tablero.moverFicha("a4 a h4");
  tablero.moverFicha("e1 a e0");
  //tablero.moverFicha("f3 a f2");
  //tablero.moverFicha("g1 a b1");

  tablero.moverFicha("e0 a d0");
  tablero.moverFicha("c0 a e0");

  tablero.moverFicha("f7 a a4");
  tablero.moverFicha("d0 a d2");

//  tablero.moverFicha("c3 a d3");
//  tablero.moverFicha("b1 a b4");




  //  tablero.moverFicha("a6 a a3");
  //  tablero.moverFicha("d1 a d5");
 // tablero.impTablero();
 // cout << tablero.validarMovimiento("b6 a b4",1);

    //cout << tablero.veriMov("c3 a c7");
  //cout << tablero.validarMovimiento("d2 a f0",1) << endl;
 // cout << tablero.validarMovimiento("d2 a b0",1) << endl;
 // cout << tablero.validarMovimiento("d2 a a5",1) << endl;
 // cout << tablero.validarMovimiento("d2 a g5",1) << endl;

   // cout << tablero.validarMovimiento("b4 a g5",1) << endl;*/

    // Probando jaque mate
    tablero.moverFicha("e6 a e4");
    tablero.moverFicha("e1 a e3");
    tablero.moverFicha("f7 a c4");
    tablero.moverFicha("d7 a f5");

    //cout << tablero.validarMovimiento("f7 a c4",1) << endl;

    //tablero.moverFicha("e1 a e0");

    tablero.jugar();


  //cout << "rey negro: Y:" << tablero.getYnegro() << " X:" << tablero.getXnegro() << endl;
  //cout << "rey blanco: Y:" << tablero.getYblanco() << " X:" << tablero.getXblanco() << endl;

  //cout << tablero.estoyEnJaque(1);

    return 0;
}

