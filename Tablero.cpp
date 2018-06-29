/*
  Archivo: Tablero.cpp
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831 - Juan Camargo COD 1741510
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co - camargo.juan@correounivalle.edu.co
  Fecha creacion: 2018-05-14
  Fecha ultima modificacion: 2018-06-25
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad: Clase que maneja todos los movimientos y validaciones de las fichas en un tablero de ajedrez.
// Colaboracion: Fichas.h

#include "Tablero.h"
#include "Fichas.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <fstream>

using namespace std;

Tablero::Tablero(){

    //Fichas Jugador Blanco Jugador 1
    Fichas pb('P',"PB","Peon Blanco",1);
    Fichas tb('T',"TB","Torre Blanca",1);
    Fichas cb('C',"CB","Caballo Blanco",1);
    Fichas ab('A',"AB","Alfil blanco",1);
    Fichas qb('Q',"QB","Reina Blanca",1);
    Fichas kb('K',"KB","Rey Blanco",1);

    //Fichas Jugador Negro Jugador 2

    Fichas pn('p',"pn","Peon Negro",2);
    Fichas tn('t',"tn","Torre Negro",2);
    Fichas cn('c',"cn","Caballo Negro",2);
    Fichas an('a',"an","Alfil Negro",2);
    Fichas qn('q',"qn","Reina Negra",2);
    Fichas kn('k',"kn","Rey Negro",2);


    //Posicionamos las fichas negras arriba en el tablero
    tablero[1][0] = pn;
    tablero[1][1] = pn;
    tablero[1][2] = pn;
    tablero[1][3] = pn;
    tablero[1][4] = pn;
    tablero[1][5] = pn;
    tablero[1][6] = pn;
    tablero[1][7] = pn;

    tablero[0][0] = tn;
    tablero[0][1] = cn;
    tablero[0][2] = an;
    tablero[0][3] = qn;
    tablero[0][4] = kn;
    tablero[0][5] = an;
    tablero[0][6] = cn;
    tablero[0][7] = tn;

    //Posicionamos las fichas blancas abajo en el tablero

    tablero[6][0] = pb;
    tablero[6][1] = pb;
    tablero[6][2] = pb;
    tablero[6][3] = pb;
    tablero[6][4] = pb;
    tablero[6][5] = pb;
    tablero[6][6] = pb;
    tablero[6][7] = pb;

    tablero[7][0] = tb;
    tablero[7][1] = cb;
    tablero[7][2] = ab;
    tablero[7][3] = qb;
    tablero[7][4] = kb;
    tablero[7][5] = ab;
    tablero[7][6] = cb;
    tablero[7][7] = tb;

    //guardamos las posiciones de los reyes para facilitar detectar jaque y jaquemate
    xBlanco = 4;
    yBlanco = 7;
    xNegro = 4;
    yNegro = 0;

    int jugadorActual=1;
}

Tablero::~Tablero()
{
    //Metodo destructor
}

void Tablero::setXnegro(int xnegro)
{
    this -> xNegro = xnegro;
}

int Tablero::getXnegro()
{
    return xNegro;
}

void Tablero::setYnegro(int ynegro)
{
    this -> yNegro = ynegro;
}

int Tablero::getYnegro()
{
    return yNegro;
}

void Tablero::setXblanco(int xblanco)
{
    this -> xBlanco = xblanco;
}

int Tablero::getXblanco()
{
    return xBlanco;
}

void Tablero::setYblanco(int yblanco)
{
    this -> yBlanco = yblanco;
}

int Tablero::getYblanco()
{
    return yBlanco;
}

void Tablero::nuevaPartida()
{
    //Fichas Jugador Blanco Jugador 1
    Fichas pb('P',"PB","Peon Blanco",1);
    Fichas tb('T',"TB","Torre Blanca",1);
    Fichas cb('C',"CB","Caballo Blanco",1);
    Fichas ab('A',"AB","Alfil blanco",1);
    Fichas qb('Q',"QB","Reina Blanca",1);
    Fichas kb('K',"KB","Rey Blanco",1);

    //Fichas Jugador Negro Jugador 2

    Fichas pn('p',"pn","Peon Negro",2);
    Fichas tn('t',"tn","Torre Negro",2);
    Fichas cn('c',"cn","Caballo Negro",2);
    Fichas an('a',"an","Alfil Negro",2);
    Fichas qn('q',"qn","Reina Negra",2);
    Fichas kn('k',"kn","Rey Negro",2);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            Fichas ficha1(' '," "," ",0);
            tablero[i][j] = ficha1;
        }
    }

    //Posicionamos las fichas negras arriba en el tablero
    tablero[1][0] = pn;
    tablero[1][1] = pn;
    tablero[1][2] = pn;
    tablero[1][3] = pn;
    tablero[1][4] = pn;
    tablero[1][5] = pn;
    tablero[1][6] = pn;
    tablero[1][7] = pn;

    tablero[0][0] = tn;
    tablero[0][1] = cn;
    tablero[0][2] = an;
    tablero[0][3] = qn;
    tablero[0][4] = kn;
    tablero[0][5] = an;
    tablero[0][6] = cn;
    tablero[0][7] = tn;

    //Posicionamos las fichas blancas abajo en el tablero

    tablero[6][0] = pb;
    tablero[6][1] = pb;
    tablero[6][2] = pb;
    tablero[6][3] = pb;
    tablero[6][4] = pb;
    tablero[6][5] = pb;
    tablero[6][6] = pb;
    tablero[6][7] = pb;

    tablero[7][0] = tb;
    tablero[7][1] = cb;
    tablero[7][2] = ab;
    tablero[7][3] = qb;
    tablero[7][4] = kb;
    tablero[7][5] = ab;
    tablero[7][6] = cb;
    tablero[7][7] = tb;

    //guardamos las posiciones de los reyes para facilitar detectar jaque y jaquemate
    xBlanco = 4;
    yBlanco = 7;
    xNegro = 4;
    yNegro = 0;


    int tamano = jugadas.size();
    for (int i = 0 ; i < tamano; i++)
    {
        jugadas.pop_back();
    }

    jugadorActual=1;
}

void Tablero::impTablero() {
    cout << endl << "      A    B    C    D    E    F    G    H";
    for(int i=0; i<8; i++)
    {
        cout << endl <<"   -----------------------------------------" << endl;
        cout << i << "  ";
        for(int j=0; j<8; j++)
        {

            if(tablero[i][j].getIdChar() == ' ')
            {
                if(j==7)
                {
                    cout << "|    |";
                }
                else
                {
                    cout << "|    ";
                }
            }
            else
            {
                if(j==7)
                {
                cout<<"| "<<tablero[i][j].getUnicode()<< " |";
                }
                else
                {
                cout<<"| "<<tablero[i][j].getUnicode()<< " ";
                }
            }
        }

    }
    cout<<'\n';
    cout<<"   -----------------------------------------" << endl;
    cout << "      A    B    C    D    E    F    G    H" << endl << endl;
}

bool Tablero::veriMov(string mov)
{
    //miramos si tiene 7 caracteres
    if(mov.length() != 7)
    {
        return false;
    }
    //comprobamos que el primer caracter sea un caracter valido
    if(mov[0] != 'a' && mov[0] != 'b' && mov[0] != 'c' && mov[0] != 'd' &&
       mov[0] != 'e' && mov[0] != 'f' && mov[0] != 'g' && mov[0] != 'h' &&
       mov[0] != 'A' && mov[0] != 'B' && mov[0] != 'C' && mov[0] != 'D' &&
       mov[0] != 'E' && mov[0] != 'F' && mov[0] != 'G' && mov[0] != 'H')
    {
        return false;
    }

    //miramos que el segundo sea un numero del 0 al 7
    if(mov[1] != '0' && mov[1] != '1' && mov[1] != '2' && mov[1] != '3' &&
       mov[1] != '4' && mov[1] != '5' && mov[1] != '6' && mov[1] != '7'){

        return false;
    }

    //esto es para chequear que el cuarto sea una a, recordemos que el formato es a4 a b7 (el a de la mitad)
    if(mov[3] != 'a' && mov[3] != 'A')
    {
        return false;
    }

    //verificamos que el destino tenga una letra valida
    if(mov[5] != 'a' && mov[5] != 'b' && mov[5] != 'c' && mov[5] != 'd' &&
       mov[5] != 'e' && mov[5] != 'f' && mov[5] != 'g' && mov[5] != 'h' &&
       mov[5] != 'A' && mov[5] != 'B' && mov[5] != 'C' && mov[5] != 'D' &&
       mov[5] != 'E' && mov[5] != 'F' && mov[5] != 'G' && mov[5] != 'H')
    {

    return false;
}
    //verificamos que el destino tenga un numero valido
    if(mov[6] != '0' && mov[6] != '1' && mov[6] != '2' && mov[6] != '3' && mov[6] != '4'
            && mov[6] != '5' && mov[6] != '6' && mov[6] != '7')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Tablero::moverFicha(string mov)
{
    //transformamos ese string en coordenadas para usarlos en la matriz
    int xIni;
    int yIni;
    int xFin;
    int yFin;


    if(mov[0] == 'a' || mov[0] == 'A')
        xIni = 0;
    else if(mov[0] == 'b' || mov[0] == 'B')
        xIni = 1;
    else if(mov[0] == 'c' || mov[0] == 'C')
        xIni = 2;
    else if(mov[0] == 'd' || mov[0] == 'D')
        xIni = 3;
    else if(mov[0] == 'e' || mov[0] == 'E')
        xIni = 4;
    else if(mov[0] == 'f' || mov[0] == 'F')
        xIni = 5;
    else if(mov[0] == 'g' || mov[0] == 'G')
        xIni = 6;
    else
        xIni = 7;

    yIni = (int)mov[1] - 48;

    if(mov[5] == 'a' || mov[5] == 'A')
        xFin = 0;
    if(mov[5] == 'b' || mov[5] == 'B')
        xFin = 1;
    if(mov[5] == 'c' || mov[5] == 'C')
        xFin = 2;
    if(mov[5] == 'd' || mov[5] == 'D')
        xFin = 3;
    if(mov[5] == 'e' || mov[5] == 'E')
        xFin = 4;
    if(mov[5] == 'f' || mov[5] == 'F')
        xFin = 5;
    if(mov[5] == 'g' || mov[5] == 'G')
        xFin = 6;
    if(mov[5] == 'h' || mov[5] == 'H')
        xFin = 7;

    yFin = (int)mov[6] - 48;

    //si la ficha que estamos moviendo es un rey, actualizamos las coordenadas de los reyes que tenemos en los atributos de clase
    if(tablero[yIni][xIni].getIdChar()=='k')
    {
        yNegro = yFin;
        xNegro = xFin;
    }
    if(tablero[yIni][xIni].getIdChar()=='K')
    {
        yBlanco = yFin;
        xBlanco = xFin;
    }

    //ahora reescribimos la matriz
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(yFin == i && xFin == j)
            {
                Fichas ficha1(' '," "," ",0);
                tablero[i][j] = tablero[yIni][xIni];
                tablero[yIni][xIni] = ficha1;
            }

        }
    }
}

void Tablero::moverFicha(int xIni, int yIni, int xFin, int yFin)
{

    if(tablero[yIni][xIni].getIdChar()=='k')
    {
        yNegro = yFin;
        xNegro = xFin;
    }
    if(tablero[yIni][xIni].getIdChar()=='K')
    {
        yBlanco = yFin;
        xBlanco = xFin;
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(yFin == i && xFin == j)
            {
                Fichas ficha1(' '," "," ",0);
                tablero[i][j] = tablero[yIni][xIni];
                tablero[yIni][xIni] = ficha1;
            }
        }
    }
}

void Tablero::devolverFicha(string mov)
{
    //transformamos ese string en coordenadas para usarlos en la matriz
    int xIni;
    int yIni;
    int xFin;
    int yFin;

    if(mov[5] == 'a' || mov[5] == 'A')
        xIni = 0;
    else if(mov[5] == 'b' || mov[5] == 'B')
        xIni = 1;
    else if(mov[5] == 'c' || mov[5] == 'C')
        xIni = 2;
    else if(mov[5] == 'd' || mov[5] == 'D')
        xIni = 3;
    else if(mov[5] == 'e' || mov[5] == 'E')
        xIni = 4;
    else if(mov[5] == 'f' || mov[5] == 'F')
        xIni = 5;
    else if(mov[5] == 'g' || mov[5] == 'G')
        xIni = 6;
    else
        xIni = 7;

    yIni = (int)mov[6] - 48;

    if(mov[0] == 'a' || mov[0] == 'A')
        xFin = 0;
    if(mov[0] == 'b' || mov[0] == 'B')
        xFin = 1;
    if(mov[0] == 'c' || mov[0] == 'C')
        xFin = 2;
    if(mov[0] == 'd' || mov[0] == 'D')
        xFin = 3;
    if(mov[0] == 'e' || mov[0] == 'E')
        xFin = 4;
    if(mov[0] == 'f' || mov[0] == 'F')
        xFin = 5;
    if(mov[0] == 'g' || mov[0] == 'G')
        xFin = 6;
    if(mov[0] == 'h' || mov[0] == 'H')
        xFin = 7;

    yFin = (int)mov[1] - 48;

    //si la ficha que estamos moviendo es un rey, actualizamos las coordenadas de los reyes que tenemos en los atributos de clase
    if(tablero[yIni][xIni].getIdChar()=='k')
    {
        yNegro = yFin;
        xNegro = xFin;
    }
    if(tablero[yIni][xIni].getIdChar()=='K')
    {
        yBlanco = yFin;
        xBlanco = xFin;
    }

    //ahora reescribimos la matriz
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(yFin == i && xFin == j)
            {
                Fichas ficha1(' '," "," ",0);
                tablero[i][j] = tablero[yIni][xIni];
                tablero[yIni][xIni] = ficha1;
            }

        }
    }
}

void Tablero::devolverFicha(int xFin, int yFin, int xIni, int yIni)
{
    if(tablero[yIni][xIni].getIdChar()=='k')
    {
        yNegro = yFin;
        xNegro = xFin;
    }
    if(tablero[yIni][xIni].getIdChar()=='K')
    {
        yBlanco = yFin;
        xBlanco = xFin;
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(yFin == i && xFin == j)
            {
                Fichas ficha1(' '," "," ",0);
                tablero[i][j] = tablero[yIni][xIni];
                tablero[yIni][xIni] = ficha1;
            }

        }
    }
}

bool Tablero::validarMovimiento(string mov, int jugador)
{
    //Transformamos el string en coordenadas para usar en la matriz
    int xIni;
    int yIni;
    int xFin;
    int yFin;

    if(mov[0] == 'a' || mov[0] == 'A')
    {
        xIni = 0;
    }
    else if(mov[0] == 'b' || mov[0] == 'B')
        xIni = 1;
    else if(mov[0] == 'c' || mov[0] == 'C')
        xIni = 2;
    else if(mov[0] == 'd' || mov[0] == 'D')
        xIni = 3;
    else if(mov[0] == 'e' || mov[0] == 'E')
        xIni = 4;
    else if(mov[0] == 'f' || mov[0] == 'F')
        xIni = 5;
    else if(mov[0] == 'g' || mov[0] == 'G')
        xIni = 6;
    else
        xIni = 7;

    yIni = (int)mov[1] - 48;

    if(mov[5] == 'a' || mov[5] == 'A')
        xFin = 0;
    if(mov[5] == 'b' || mov[5] == 'B')
        xFin = 1;
    if(mov[5] == 'c' || mov[5] == 'C')
        xFin = 2;
    if(mov[5] == 'd' || mov[5] == 'D')
        xFin = 3;
    if(mov[5] == 'e' || mov[5] == 'E')
        xFin = 4;
    if(mov[5] == 'f' || mov[5] == 'F')
        xFin = 5;
    if(mov[5] == 'g' || mov[5] == 'G')
        xFin = 6;
    if(mov[5] == 'h' || mov[5] == 'H')
        xFin = 7;

    yFin = (int)mov[6] - 48;

    // espacios a moverse
    int difFilas = yFin - yIni;
    int difCol = xFin - xIni;

    //Hacemos unas validaciones en general
    if(tablero[yIni][xIni].getIdChar()==' ')
    {
        cout << "Seleccionaste una casilla vacia" << endl;
        return false;
    }
    if(tablero[yIni][xIni].getJugador()!=jugador)
    {
        cout << "Esta no es tu ficha." << endl;
        return false;
    }
    if(tablero[yFin][xFin].getJugador()==jugador)
    {
        cout << "Tienes una ficha tuya alli" << endl;
        return false;
    }

    //Ahora empezamos con las validaciones dependiendo del tipo de ficha.
    //Validaremos donde pueden comer las fichas dependiendo su tipo y las coliciones en los movimientos.

    // Validacion Peones Blancos

    if(tablero[yIni][xIni].getIdChar() == 'P' && jugador == 1)
    {
        if(tablero[yFin][xFin].getJugador() == 2 && difFilas == -1 && abs(difCol) == 1)
        {
            cout << "te has comido " << tablero[yFin][xFin].getNombre() << " del jugador contrario" << endl;
            return true;
        }
        else if(yIni != 6 && abs(difFilas) >= 2)
        {
            cout << "No puedes mover mas de 1 casilla." << endl;
            return false;
        }
        else if(yIni == 6 && abs(difFilas) > 2)
        {
            cout << "No puedes mover mas de dos casillas." << endl;
            return false;
        }
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            cout << "Hay alguien ocupado esta casilla." << endl;
            return false;
        }
        else if(yIni == 6 && tablero[yIni-1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            cout << "Alguien obstruye el paso." << endl;
            return false;
        }
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1)
        {
            cout << "Hay alguien ocupado esta casilla." << endl;
            return false;
        }
        else if(difFilas < -1 && yIni!=6)
        {
            cout << "No puedes mover mas de 1 espacio hacia adelante" << endl;
            return false;
        }
        else if(abs(difCol) > 0)
        {
            cout << "No puedes hacer este movimiento" << endl;
            return false;
        }
        else if(yFin > yIni)
        {
            cout << "No puedes mover hacia atras" << endl;
            return false;
        }
        else if(tablero[yIni-1][xIni].getIdChar()!=' ')
        {
            cout << "Esta ocupada esta casilla." << endl;
            return false;
        }
        else
        {
            return true;
        }
    }

    // Validacion Peones Negros

    if(tablero[yIni][xIni].getIdChar() == 'p' && jugador == 2)
    {
        if(tablero[yFin][xFin].getJugador() == 1 && difFilas == 1 && abs(difCol) == 1)
        {
            cout << "te has comido " << tablero[yFin][xFin].getNombre() << " del jugador contrario" << endl;
            return true;
        }
        else if(yIni != 1 && abs(difFilas) >= 2)
        {
            cout << "No puedes mover mas de 1 casilla." << endl;
            return false;
        }
        else if(yIni == 1 && abs(difFilas) > 2)
        {
            cout << "No puedes mover mas de dos casillas." << endl;
            return false;
        }
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            cout << "Hay alguien ocupado esta casilla." << endl;
            return false;
        }
        else if(yIni == 1 && tablero[yIni+1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            cout << "Alguien obstruye el paso." << endl;
            return false;
        }
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1)
        {
            cout << "Hay alguien ocupado esta casilla." << endl;
            return false;
        }
        else if(difFilas > 1 && yIni!=1)
        {
            cout << "No puedes mover mas de 1 espacio hacia adelante" << endl;
            return false;
        }
        else if(abs(difCol) > 0)
        {
            cout << "No puedes hacer este movimiento" << endl;
            return false;
        }
        else if(yFin < yIni)
        {
            cout << "No puedes mover hacia atras" << endl;
            return false;
        }
        else if(tablero[yIni+1][xIni].getIdChar()!=' ')
        {
            cout << "Esta ocupada esta casilla." << endl;
            return false;
        }
        else
        {
            return true;
        }
    }

    //Rey de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'K' || tablero[yIni][xIni].getIdChar()== 'k')
    {
        if(abs(difCol) > 1 || abs(difFilas) > 1)
        {
            cout << "El rey solo puede mover un espacio" << endl;
            return false;
        }
        else if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            cout << "Te has comido " << tablero[yFin][xFin].getNombre() << endl;
            return true;
        }
        else
        {
            return true;
        }
    }

    //Torres de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'T' || tablero[yIni][xIni].getIdChar()== 't')
    {
        if(abs(difCol) != 0 && abs(difFilas) != 0)
        {
            cout << "La torre no puede mover asi." << endl;
            return false;
        }
        else if(difCol == 0 && difFilas > 0) // Validacion de arriba hacia abajo
        {
            for(int i=yIni+1;i<yFin;i++)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol == 0 && difFilas < 0) // Validacion de abajo hacia arriba
        {
            for(int i=yIni-1;i>yFin;i--)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol > 0 && difFilas == 0) // Validacion de izquierda a derecha
        {
            for(int i=xIni+1;i<xFin;i++)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol < 0 && difFilas == 0) // Validacion de derecha a izquierda
        {
            for(int i=xIni-1;i>xFin;i--)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }

        if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            cout << "Te has comido " << tablero[yFin][xFin].getNombre() << endl;
            return true;
        }
        else
        {
            return true;
        }
    }

    //Alfiles de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'a' || tablero[yIni][xIni].getIdChar()== 'A')
    {
        if(abs(difCol)!=abs(difFilas))
        {
            cout << "Los alfiles no pueden mover asi." << endl;
            return false;
        }
        else if(difCol > 0 && difFilas < 0)
        {
            int x = xIni+1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino arriba a la derecha." << endl;
                    return false;
                }
                y = y-1;
                x = x+1;
            }
        }
        else if(difCol > 0 && difFilas > 0)
        {
            int x = xIni+1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino abajo a la derecha." << endl;
                    return false;
                }
                y = y+1;
                x = x+1;
            }
        }
        else if(difCol < 0 && difFilas < 0)
        {
            int x = xIni-1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino arriba a la izquierda." << endl;
                    return false;
                }
                y = y-1;
                x = x-1;
            }
        }
        else if(difCol < 0 && difFilas > 0)
        {
            int x = xIni-1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino abajo a la izquierda." << endl;
                    return false;
                }
                y = y+1;
                x = x-1;
            }
        }

        if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            cout << "Te has comido " << tablero[yFin][xFin].getNombre() << endl;
            return true;
        }

        else
        {
            return true;
        }
    }

    //Caballos cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'c' || tablero[yIni][xIni].getIdChar()== 'C')
    {
        if (abs(difCol)*abs(difFilas) != 2)
        {
            cout << "Los caballos no pueden mover asi." << endl;
            return false;
        }

        if (tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            cout << "Te has comido " << tablero[yFin][xFin].getNombre() << endl;
            return true;
        }
        else
        {
            return true;
        }
    }


    //Reina de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'q' || tablero[yIni][xIni].getIdChar()== 'Q')
    {
        if(abs(difCol) != 0 && abs(difFilas) != 0 && abs(difCol)!=abs(difFilas))
        {
            cout << "La Reina no puede mover asi." << endl;
            return false;
        }
        else if(difCol == 0 && difFilas > 0) // Validacion de arriba hacia abajo
        {
            for(int i=yIni+1;i<yFin;i++)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol == 0 && difFilas < 0) // Validacion de abajo hacia arriba
        {
            for(int i=yIni-1;i>yFin;i--)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol > 0 && difFilas == 0) // Validacion de izquierda a derecha
        {
            for(int i=xIni+1;i<xFin;i++)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol < 0 && difFilas == 0) // Validacion derecha a izquierda
        {
            for(int i=xIni-1;i>xFin;i--)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    cout << "Hay una ficha en medio del camino." << endl;
                    return false;
                }
            }
        }
        else if(difCol > 0 && difFilas < 0)
        {
            int x = xIni+1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino arriba a la derecha." << endl;
                    return false;
                }
                y = y-1;
                x = x+1;
            }
        }
        else if(difCol > 0 && difFilas > 0)
        {
            int x = xIni+1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino abajo a la derecha." << endl;
                    return false;
                }
                y = y+1;
                x = x+1;
            }
        }
        else if(difCol < 0 && difFilas < 0)
        {
            int x = xIni-1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino arriba a la izquierda." << endl;
                    return false;
                }
                y = y-1;
                x = x-1;
            }
        }
        else if(difCol < 0 && difFilas > 0)
        {
            int x = xIni-1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    cout << "Hay una ficha bloqueando el camino abajo a la izquierda." << endl;
                    return false;
                }
                y = y+1;
                x = x-1;
            }
        }

        if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            cout << "Te has comido " << tablero[yFin][xFin].getNombre() << endl;
            return true;
        }
        else
        {
            return true;
        }
    }
}

bool Tablero::validarMovimiento(int xIni, int yIni, int xFin, int yFin, int jugador)
{
    // espacios a moverse
    int difFilas = yFin - yIni;
    int difCol = xFin - xIni;

    if(tablero[yIni][xIni].getIdChar()==' ')
    {
        return false;
    }
    if(tablero[yIni][xIni].getJugador()!=jugador)
    {
        return false;
    }
    if(tablero[yFin][xFin].getJugador()==jugador)
    {
        return false;
    }

    // Validacion Peones Blancos

    if(tablero[yIni][xIni].getIdChar() == 'P' && jugador == 1)
    {
        if(tablero[yFin][xFin].getJugador() == 2 && difFilas == -1 && abs(difCol) == 1)
        {
            return true;
        }
        else if(yIni != 6 && abs(difFilas) >= 2)
        {
            return false;
        }
        else if(yIni == 6 && abs(difFilas) > 2)
        {
            return false;
        }
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            return false;
        }
        else if(yIni == 6 && tablero[yIni-1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            return false;
        }
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1)
        {
            return false;
        }
        else if(difFilas < -1 && yIni!=6)
        {
            return false;
        }
        else if(abs(difCol) > 0)
        {
            return false;
        }
        else if(yFin > yIni)
        {
            return false;
        }
        else if(tablero[yIni-1][xIni].getIdChar()!=' ')
        {
            return false;
        }
        else
        {
            return true;
        }


    }

    // Validacion Peones Negros

    if(tablero[yIni][xIni].getIdChar() == 'p' && jugador == 2)
    {
        if(tablero[yFin][xFin].getJugador() == 1 && difFilas == 1 && abs(difCol) == 1)
        {
            return true;
        }
        else if(yIni != 1 && abs(difFilas) >= 2)
        {
            return false;
        }
        else if(yIni == 1 && abs(difFilas) > 2)
        {
            return false;
        }
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            return false;
        }
        else if(yIni == 1 && tablero[yIni+1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2)
        {
            return false;
        }
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1)
        {
            return false;
        }
        else if(difFilas > 1 && yIni!=1)
        {
            return false;
        }
        else if(abs(difCol) > 0)
        {
            return false;
        }
        else if(yFin < yIni)
        {
            return false;
        }
        else if(tablero[yIni+1][xIni].getIdChar()!=' ')
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //Rey de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'K' || tablero[yIni][xIni].getIdChar()== 'k')
    {
        if(abs(difCol) > 1 || abs(difFilas) > 1)
        {
            return false;
        }
        else if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            return true;
        }
        else
        {
            return true;
        }

    }

    //Torres de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'T' || tablero[yIni][xIni].getIdChar()== 't')
    {
        if(abs(difCol) != 0 && abs(difFilas) != 0)
        {
            return false;
        }
        else if(difCol == 0 && difFilas > 0)
        {
            for(int i=yIni+1;i<yFin;i++)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol == 0 && difFilas < 0)
        {
            for(int i=yIni-1;i>yFin;i--)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol > 0 && difFilas == 0)
        {
            for(int i=xIni+1;i<xFin;i++)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol < 0 && difFilas == 0)
        {
            for(int i=xIni-1;i>xFin;i--)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }

        if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
           return true;
        }
        else
        {
            return true;
        }
    }

    //Alfiles de cualquier jugador

    if(tablero[yIni][xIni].getIdChar()== 'a' || tablero[yIni][xIni].getIdChar()== 'A')
    {
        if(abs(difCol)!=abs(difFilas))
        {
            return false;
        }
        else if(difCol > 0 && difFilas < 0)
        {
            int x = xIni+1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y-1;
                x = x+1;
            }
        }
        else if(difCol > 0 && difFilas > 0)
        {
            int x = xIni+1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y+1;
                x = x+1;
            }
        }
        else if(difCol < 0 && difFilas < 0)
        {
            int x = xIni-1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                   return false;
                }
                y = y-1;
                x = x-1;
            }
        }
        else if(difCol < 0 && difFilas > 0)
        {
            int x = xIni-1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y+1;
                x = x-1;
            }
        }

        if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            return true;
        }

        else
        {
            return true;
        }
    }

    //Caballos cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'c' || tablero[yIni][xIni].getIdChar()== 'C')
    {
        if (abs(difCol)*abs(difFilas) != 2)
        {
            return false;
        }

        if (tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            return true;
        }
        else
        {
            return true;
        }
    }


    //Reina de cualquier jugador
    if(tablero[yIni][xIni].getIdChar()== 'q' || tablero[yIni][xIni].getIdChar()== 'Q')
    {
        if(abs(difCol) != 0 && abs(difFilas) != 0 && abs(difCol)!=abs(difFilas))
        {
            return false;
        }
        else if(difCol == 0 && difFilas > 0)
        {
            for(int i=yIni+1;i<yFin;i++)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol == 0 && difFilas < 0)
        {
            for(int i=yIni-1;i>yFin;i--)
            {
                if(tablero[i][xIni].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol > 0 && difFilas == 0)
        {
            for(int i=xIni+1;i<xFin;i++)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol < 0 && difFilas == 0)
        {
            for(int i=xIni-1;i>xFin;i--)
            {
                if(tablero[yIni][i].getIdChar()!=' ')
                {
                    return false;
                }
            }
        }
        else if(difCol > 0 && difFilas < 0)
        {
            int x = xIni+1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y-1;
                x = x+1;
            }
        }
        else if(difCol > 0 && difFilas > 0)
        {
            int x = xIni+1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y+1;
                x = x+1;
            }
        }
        else if(difCol < 0 && difFilas < 0)
        {
            int x = xIni-1;
            int y = yIni-1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y-1;
                x = x-1;
            }
        }
        else if(difCol < 0 && difFilas > 0)
        {
            int x = xIni-1;
            int y = yIni+1;
            while(y!=yFin)
            {
                if(tablero[y][x].getIdChar()!=' ')
                {
                    return false;
                }
                y = y+1;
                x = x-1;
            }
        }

        if(tablero[yFin][xFin].getJugador()!=jugador && tablero[yFin][xFin].getJugador()!=0)
        {
            return true;
        }
        else
        {
            return true;
        }
    }
}

bool Tablero::estoyEnJaque(int jugadorA,int opci)
{
    bool devolver = false; //boleano que se devolvera

    //Aqui buscaremos todas las fichas enemigas y construiremos un movimiento(string) de todas las fichas enemigas hacia mi rey.
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(tablero[i][j].getJugador()!=jugadorA && tablero[i][j].getJugador()!=0)
            {
                string movim="       ";

                if(j == 0)
                    movim[0] = 'a';
                else if(j == 1)
                    movim[0] = 'b';
                else if(j == 2)
                    movim[0] = 'c';
                else if(j == 3)
                    movim[0] = 'd';
                else if(j == 4)
                    movim[0] = 'e';
                else if(j == 5)
                    movim[0] = 'f';
                else if(j == 6)
                    movim[0] = 'g';
                else
                    movim[0] = 'h';

                if(i == 0)
                    movim[1] = '0';
                else if(i == 1)
                    movim[1] = '1';
                else if(i == 2)
                    movim[1] = '2';
                else if(i == 3)
                    movim[1] = '3';
                else if(i == 4)
                    movim[1] = '4';
                else if(i == 5)
                    movim[1] = '5';
                else if(i == 6)
                    movim[1] = '6';
                else
                    movim[1] = '7';

                movim[2] = ' ';
                movim[3] = 'a';
                movim[4] = ' ';

                if(jugadorA==2)
                {
                    int xrey = getXnegro();

                    if(xrey == 0)
                        movim[5] = 'a';
                    else if(xrey == 1)
                        movim[5] = 'b';
                    else if(xrey == 2)
                        movim[5] = 'c';
                    else if(xrey == 3)
                        movim[5] = 'd';
                    else if(xrey == 4)
                        movim[5] = 'e';
                    else if(xrey == 5)
                        movim[5] = 'f';
                    else if(xrey == 6)
                        movim[5] = 'g';
                    else
                        movim[5] = 'h';

                    int yrey = getYnegro();

                    if(yrey == 0)
                        movim[6] = '0';
                    else if(yrey == 1)
                        movim[6] = '1';
                    else if(yrey == 2)
                        movim[6] = '2';
                    else if(yrey == 3)
                        movim[6] = '3';
                    else if(yrey == 4)
                        movim[6] = '4';
                    else if(yrey == 5)
                        movim[6] = '5';
                    else if(yrey == 6)
                        movim[6] = '6';
                    else
                        movim[5] = '7';
                }
                else
                {
                    int xrey = getXblanco();

                    if(xrey == 0)
                        movim[5] = 'a';
                    else if(xrey == 1)
                        movim[5] = 'b';
                    else if(xrey == 2)
                        movim[5] = 'c';
                    else if(xrey == 3)
                        movim[5] = 'd';
                    else if(xrey == 4)
                        movim[5] = 'e';
                    else if(xrey == 5)
                        movim[5] = 'f';
                    else if(xrey == 6)
                        movim[5] = 'g';
                    else
                        movim[5] = 'h';

                    int yrey = getYblanco();

                    if(yrey == 0)
                        movim[6] = '0';
                    else if(yrey == 1)
                        movim[6] = '1';
                    else if(yrey == 2)
                        movim[6] = '2';
                    else if(yrey == 3)
                        movim[6] = '3';
                    else if(yrey == 4)
                        movim[6] = '4';
                    else if(yrey == 5)
                        movim[6] = '5';
                    else if(yrey == 6)
                        movim[6] = '6';
                    else
                        movim[6] = '7';
                }

                cout.setstate(ios_base::failbit); // para impedir que se impriman los couts
                if(jugadorA==1) //cuando el jugador actual es el de las fichas blancas (jugador 1)
                {
                    if(validarMovimiento(movim,2)) //valido ese movimiento de la ficha enemiga(negra) hacia mi rey.
                    {
                        cout.clear(); // para volver a dejar que se impriman los couts
                        if(opci==0){
                            cout << "La ficha " << tablero[i][j].getNombre();
                            cout << " te tiene en jaque." << endl;}
                        else if(opci==2){}
                        else{
                            cout << "La ficha " << tablero[i][j].getNombre();
                            cout << " te tendria en jaque si haces este movimiento" << endl;}
                        devolver = true;
                    }
                }
                else //cuando el jugador actual es el de las fichas negras (jugador 2)
                {
                    if(validarMovimiento(movim,1))
                    {
                        cout.clear();
                        if(opci==0){
                            cout << "La ficha " << tablero[i][j].getNombre();
                            cout << " te tiene en jaque." << endl;}
                        else if(opci==2){}
                        else{
                            cout << "La ficha " << tablero[i][j].getNombre();
                            cout << " te tendria en jaque si haces este movimiento" << endl;}
                        devolver = true;
                    }
                }
                cout.clear();
            }
        }
    }
    return devolver;
}

bool Tablero::estoyEnJaqueMate(int jugadorA)
{
    bool devolver = false;
    //Aqui buscaremos todas las fichas enemigas y construiremos un movimiento(string) de todas las fichas enemigas hacia mi rey.
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(tablero[i][j].getJugador()!=jugadorA && tablero[i][j].getJugador()!=0)
            {
                string movim="       ";

                if(j == 0)
                    movim[0] = 'a';
                else if(j == 1)
                    movim[0] = 'b';
                else if(j == 2)
                    movim[0] = 'c';
                else if(j == 3)
                    movim[0] = 'd';
                else if(j == 4)
                    movim[0] = 'e';
                else if(j == 5)
                    movim[0] = 'f';
                else if(j == 6)
                    movim[0] = 'g';
                else
                    movim[0] = 'h';

                if(i == 0)
                    movim[1] = '0';
                else if(i == 1)
                    movim[1] = '1';
                else if(i == 2)
                    movim[1] = '2';
                else if(i == 3)
                    movim[1] = '3';
                else if(i == 4)
                    movim[1] = '4';
                else if(i == 5)
                    movim[1] = '5';
                else if(i == 6)
                    movim[1] = '6';
                else
                    movim[1] = '7';

                movim[2] = ' ';
                movim[3] = 'a';
                movim[4] = ' ';

                if(jugadorA==2)
                {
                    int xrey = getXnegro();

                    if(xrey == 0)
                        movim[5] = 'a';
                    else if(xrey == 1)
                        movim[5] = 'b';
                    else if(xrey == 2)
                        movim[5] = 'c';
                    else if(xrey == 3)
                        movim[5] = 'd';
                    else if(xrey == 4)
                        movim[5] = 'e';
                    else if(xrey == 5)
                        movim[5] = 'f';
                    else if(xrey == 6)
                        movim[5] = 'g';
                    else
                        movim[5] = 'h';

                    int yrey = getYnegro();

                    if(yrey == 0)
                        movim[6] = '0';
                    else if(yrey == 1)
                        movim[6] = '1';
                    else if(yrey == 2)
                        movim[6] = '2';
                    else if(yrey == 3)
                        movim[6] = '3';
                    else if(yrey == 4)
                        movim[6] = '4';
                    else if(yrey == 5)
                        movim[6] = '5';
                    else if(yrey == 6)
                        movim[6] = '6';
                    else
                        movim[5] = '7';
                }
                else
                {
                    int xrey = getXblanco();

                    if(xrey == 0)
                        movim[5] = 'a';
                    else if(xrey == 1)
                        movim[5] = 'b';
                    else if(xrey == 2)
                        movim[5] = 'c';
                    else if(xrey == 3)
                        movim[5] = 'd';
                    else if(xrey == 4)
                        movim[5] = 'e';
                    else if(xrey == 5)
                        movim[5] = 'f';
                    else if(xrey == 6)
                        movim[5] = 'g';
                    else
                        movim[5] = 'h';

                    int yrey = getYblanco();

                    if(yrey == 0)
                        movim[6] = '0';
                    else if(yrey == 1)
                        movim[6] = '1';
                    else if(yrey == 2)
                        movim[6] = '2';
                    else if(yrey == 3)
                        movim[6] = '3';
                    else if(yrey == 4)
                        movim[6] = '4';
                    else if(yrey == 5)
                        movim[6] = '5';
                    else if(yrey == 6)
                        movim[6] = '6';
                    else
                        movim[6] = '7';
                }

                cout.setstate(ios_base::failbit);// para impedir que se impriman los couts
                if(jugadorA==1) //cuando el jugador actual es el de las fichas blancas (jugador 1)
                {
                    if(validarMovimiento(movim,2)) //valido ese movimiento de la ficha enemiga(negra) hacia mi rey.
                    {
                        cout.clear();// para volver a dejar que se impriman los couts
                        // Si ninguna de mis fichas(blancas) se puede interponer o comerse la ficha que hace jaque(negra) y si mi rey(blanco) no puede mover
                        if(!interponerEnJaque(tablero[i][j].getIdChar(),i,j,jugadorA) && !reyPuedeMover(jugadorA))
                        {
                            cout << "Estas en jaque mate, has perdido." << endl;
                            cout << "El Jugador de las fichas Negras ha ganado." << endl;
                            devolver = true;
                        }
                    }
                }
                else //cuando el jugador actual es el de las fichas negras (jugador 2)
                {
                    if(validarMovimiento(movim,1)) //valido ese movimiento de la ficha enemiga(blanca) hacia mi rey.
                    {
                        cout.clear();// para volver a dejar que se impriman los couts
                        // Si ninguna de mis fichas(negras) se puede interponer o comerse la ficha que hace jaque(blanca) y si mi rey(negro) no puede mover
                        if(!interponerEnJaque(tablero[i][j].getIdChar(),i,j,jugadorA) && !reyPuedeMover(jugadorA))
                        {
                            cout << "Estas en jaque mate, has perdido." << endl;
                            cout << "El Jugador de las fichas Blancas ha ganado." << endl;
                            devolver = true;
                        }
                    }
                }
                cout.clear();
            }
        }
    }
    return devolver;
}

bool Tablero::interponerEnJaque(char tipoF, int yIni, int xIni, int jugadorA)
{
    // Ejemplo (torreNegra, xTorreNegra, yTorreNegra, 1(jugadorFichasBlancas)
    // Esta torre negra le esta haciendo jaque al rey blanco.
    // Miro el trayecto de esta torre negra y el rey blanco y valido si alguna ficha blanca se puede atravesar en ese trayecto
    // o se puede comer esta torre negra.

    int xFin;
    int yFin;
    if(jugadorA==1) //saco las coordenadas del rey del jugador actual.
    {
        xFin = getXblanco();
        yFin = getYblanco();
    } else
    {
        xFin = getXnegro();
        yFin = getYnegro();
    }

    // espacios a moverse
    int difFilas = yFin - yIni;
    int difCol = xFin - xIni;

    //Cuando la que hace jaque es una torre
    if(tipoF=='t' || tipoF=='T')
    {
        if(difCol > 0 && difFilas == 0)
        {
            for(int i=xIni;i<xFin;i++)
            {
                for(int k=0;k<8;k++) // aqui ya empiezo la busqueda de fichas del rey en jaque
                {
                     for(int l=0;l<8;l++)
                     {
                         if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                         {
                             if(validarMovimiento(l,k,i,yIni,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                             {
                                 return true;
                             }
                         }
                     }
                }
            }
        }
        else if(difCol == 0 && difFilas > 0)
        {
            for(int i=yIni;i<yFin;i++)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,xIni,i,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if(difCol == 0 && difFilas < 0)
        {
            for(int i=yIni;i>yFin;i--)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,xIni,i,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if(difCol < 0 && difFilas == 0)
        {
            for(int i=xIni;i>xFin;i--)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    //cuando la que hace jaque es un alfil
    if(tipoF=='a' || tipoF=='A')
    {
        if(difCol > 0 && difFilas < 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y-1;
                x = x+1;
            }
        }
        else if(difCol > 0 && difFilas > 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y+1;
                x = x+1;
            }
        }
        else if(difCol < 0 && difFilas < 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y-1;
                x = x-1;
            }
        }
        else if(difCol < 0 && difFilas > 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {

                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y+1;
                x = x-1;
            }
        }
    }

    //cuando la que hace el jaque es una reina

    if(tipoF=='q' || tipoF=='Q')
    {
        if(difCol > 0 && difFilas < 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y-1;
                x = x+1;
            }
        }
        else if(difCol > 0 && difFilas > 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y+1;
                x = x+1;
            }
        }
        else if(difCol < 0 && difFilas < 0)
        {
            int x = xIni;
            int y = yIni;

            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y-1;
                x = x-1;
            }
        }
        else if(difCol < 0 && difFilas > 0)
        {
            int x = xIni;
            int y = yIni;
            while(y!=yFin)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
                y = y+1;
                x = x-1;
            }
        }
        else if(difCol > 0 && difFilas == 0)
        {
            for(int i=xIni;i<xFin;i++)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {

                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if(difCol == 0 && difFilas > 0)
        {

            for(int i=yIni;i<yFin;i++)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,xIni,i,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if(difCol == 0 && difFilas < 0)
        {
            for(int i=yIni;i>yFin;i--)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,xIni,i,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if(difCol < 0 && difFilas == 0)
        {
            for(int i=xIni;i>xFin;i--)
            {
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    if(tipoF=='c' || tipoF=='C' || tipoF=='p' || tipoF=='P')
    {
        for(int k=0;k<8;k++)
        {
            for(int l=0;l<8;l++)
            {
                if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin)) // valido si la ficha es del jugador en jaque y no es el rey en jaque
                {
                    if(validarMovimiento(l,k,xIni,yIni,jugadorA)) // ahora miro si esa ficha puede llegar a esa posicion e interrumpir el jaque
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Tablero::reyPuedeMover(int jugadorA)
{
    // La logica en general es mirar a donde se puede mover el rey para salir del jaque.

    int xIni;
    int yIni;
    int xTemp, yTemp;
    if(jugadorA==1) // conseguimos las coordenadas del rey del jugador actual
    {
        xIni = getXblanco();
        yIni = getYblanco();
    } else
    {
        xIni = getXnegro();
        yIni = getYnegro();
    }

    cout.setstate(ios_base::failbit);

    if(validarMovimiento(xIni,yIni,xIni-1,yIni-1,jugadorA) && yIni!=0 && xIni!=0)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni-1;
        yTemp = yIni-1;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni-1,yIni-1);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni-1,yIni-1);
            tablero[yIni-1][xIni-1] = temp;// vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni-1,yIni-1);
        tablero[yIni-1][xIni-1] = temp;// vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni,yIni-1,jugadorA) && yIni!=0)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni;
        yTemp = yIni-1;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni,yIni-1);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni,yIni-1);
            tablero[yIni-1][xIni] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni,yIni-1);
        tablero[yIni-1][xIni] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni+1,yIni-1,jugadorA) && yIni!=0 && xIni!=7)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni+1;
        yTemp = yIni-1;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni+1,yIni-1);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni+1,yIni-1);
            tablero[yIni-1][xIni+1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni+1,yIni-1);
        tablero[yIni-1][xIni+1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni-1,yIni,jugadorA) && xIni!=0)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni-1;
        yTemp = yIni;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni-1,yIni);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni-1,yIni);
            tablero[yIni][xIni-1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni-1,yIni);
        tablero[yIni][xIni-1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni+1,yIni,jugadorA) && xIni!=7)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni+1;
        yTemp = yIni;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni+1,yIni);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni+1,yIni);
            tablero[yIni][xIni+1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni+1,yIni);
        tablero[yIni][xIni+1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni-1,yIni+1,jugadorA) && xIni!=0 && yIni!=7)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni-1;
        yTemp = yIni+1;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni-1,yIni+1);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni-1,yIni+1);
            tablero[yIni+1][xIni-1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni-1,yIni+1);
        tablero[yIni+1][xIni-1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni,yIni+1,jugadorA) && yIni!=7)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni;
        yTemp = yIni+1;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni,yIni+1);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni,yIni+1);
            tablero[yIni+1][xIni] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni,yIni+1);
        tablero[yIni+1][xIni] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }

    if(validarMovimiento(xIni,yIni,xIni+1,yIni+1,jugadorA) && xIni!=7 && yIni!=7)
    {
        // Aqui copiare la casilla destino a un temporal, ya que si hay una ficha en la casilla destino esta desaparece
        xTemp = xIni+1;
        yTemp = yIni+1;
        Fichas temp = tablero[yTemp][xTemp];

        moverFicha(xIni,yIni,xIni+1,yIni+1);
        if(!estoyEnJaque(jugadorA,2))
        {
            devolverFicha(xIni,yIni,xIni+1,yIni+1);
            tablero[yIni+1][xIni+1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
            return true;
        }
        devolverFicha(xIni,yIni,xIni+1,yIni+1);
        tablero[yIni+1][xIni+1] = temp; // vuelvo y pongo la ficha que estaba originalmente en la casilla
    }
    cout.clear();

    return false;
}

void Tablero::jugar()
{
    bool gameover=false; // determina cuando acaba el juego
    //int jugadorActual=1; //El jugador que empieza
    string jugada;

    while(!gameover) //mientras que el juego no este terminado
    {
        bool movValido = false; //para validar que el movimiento sea correcto
        impTablero(); //imprima el tablero

        cout << "Turno para ";
        if(jugadorActual==1)
        {
            cout << "fichas blancas." << endl;
        }
        else
        {
            cout << "fichas negras." << endl;
        }

        if(estoyEnJaque(jugadorActual,0)) // Verifico si el jugadorA esta en jaque
        {
            if(estoyEnJaqueMate(jugadorActual))  //Verifico si el jugadorA esta en jaque mate
            {
                movValido=true;
                gameover=true;
            }
        }

        while(!movValido) //mientras que el movimiento no sea valido
        {
            cout << "Escribe menu para ir al menu o jugadas para mostrar las jugadas de la partida" << endl;
            cout << "Introduzca su jugada con el siguiente formato (a5 a b7):";
            getline(cin, jugada);

            if(jugada == "menu")
            {
                menuPpal();
            }
            else if(jugada == "jugadas")
            {
                mostrarJugadas();
            }
            else if(veriMov(jugada)) // verifico que la persona haya escrito un movimiento correcto (formato correcto)
            {
                if(validarMovimiento(jugada,jugadorActual)) // Si la jugada es valida
                {
                    guardarJugada(jugada); // guarda la jugada
                    moverFicha(jugada); // entonces mueva la ficha
                    if(estoyEnJaque(jugadorActual,1)) // si despues de mover esta ficha quedo en jaque entonces
                    {
                        devolverFicha(jugada); //devuelva la ficha
                        borrarUltimaJugada(); // borra la ultima jugada en caso que le toque devolverse
                    }
                    else
                    {
                        movValido = true; // sino mueva la ficha
                    }
                }
            }
            else
            {
                cout << "Comprueba el formato del movimiento." << endl;
            }
        }
        system("pause");//hago un pause para alcanzar a ver el mensaje acerca de la jugada.
        system("cls");
        //Sleep(1000); //hago un sleep para alcanzar a ver el mensaje acerca de la jugada.
        if(jugadorActual==1) //hago el cambio de jugador
        {
            jugadorActual=2;
        }
        else
        {
            jugadorActual=1;
        }
    }
}

void Tablero::guardarPartida(){

    ofstream guardar;

    guardar.open("partida.txt", ios::out);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(tablero[i][j].getIdChar()!=' ')
            {
                guardar<<tablero[i][j].getIdChar()<<i<<j<<endl;
            }

        }
    }
    guardar<<"---"<<endl;
    vector<string>::iterator it;
    for(it = jugadas.begin(); it != jugadas.end(); it++)
    {
        guardar <<(*it) << endl;
    }

    guardar<<"***"<<endl;
    guardar<<'j'<<jugadorActual<<endl;

    cout << "Partida guardada con exito" << endl;
    guardar.close();
}

void Tablero::cargarPartida()
{
    //Fichas Jugador Blanco Jugador 1
    Fichas pb('P', "PB", "Peon Blanco", 1);
    Fichas tb('T', "TB", "Torre Blanca", 1);
    Fichas cb('C', "CB", "Caballo Blanco", 1);
    Fichas ab('A', "AB", "Alfil blanco", 1);
    Fichas qb('Q', "QB", "Reina Blanca", 1);
    Fichas kb('K', "KB", "Rey Blanco", 1);

    //Fichas Jugador Negro Jugador 2

    Fichas pn('p', "pn", "Peon Negro", 2);
    Fichas tn('t', "tn", "Torre Negro", 2);
    Fichas cn('c', "cn", "Caballo Negro", 2);
    Fichas an('a', "an", "Alfil Negro", 2);
    Fichas qn('q', "qn", "Reina Negra", 2);
    Fichas kn('k', "kn", "Rey Negro", 2);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
           Fichas ficha1(' '," "," ",0);
           tablero[i][j] = ficha1;
        }
    }

    int tamano = jugadas.size();
    for (int i = 0 ; i < tamano; i++)
    {
        jugadas.pop_back();
    }

    ifstream abrir;
    string texto;
    int numero;
    int contador=0;
    abrir.open("partida.txt", ios::in);
    while (!abrir.eof()) {

    getline(abrir, texto);

    if(contador==2)
    {
        jugadorActual = (int)texto[1] - 48;
        //cout << texto[1] << endl;
    }
    if(contador==1)
    {
        jugadas.push_back(texto);
        if(texto[0]=='*')
        {
            contador=2;
        }
    }
    if(contador==0)
    {
        int y = (int) texto[1] - 48;
        int x = (int) texto[2] - 48;

        if(texto[0]=='t')
        {
            tablero[y][x] = tn;
        }
        if(texto[0]=='T')
        {
            tablero[y][x] = tb;
        }
        if(texto[0]=='c')
        {
            tablero[y][x] = cn;
        }
        if(texto[0]=='C')
        {
            tablero[y][x] = cb;
        }
        if(texto[0]=='a')
        {
            tablero[y][x] = an;
        }
        if(texto[0]=='A')
        {
            tablero[y][x] = ab;
        }
        if(texto[0]=='q')
        {
            tablero[y][x] = qn;
        }
        if(texto[0]=='Q')
        {
            tablero[y][x] = qb;
        }
        if(texto[0]=='k')
        {
            tablero[y][x] = kn;
            xNegro = x;
            yNegro = y;
        }
        if(texto[0]=='K')
        {
            tablero[y][x] = kb;
            xBlanco = x;
            yBlanco = y;
        }
        if(texto[0]=='p')
        {
            tablero[y][x] = pn;
        }
        if(texto[0]=='P')
        {
            tablero[y][x] = pb;
        }
        if(texto[0]=='-')
        {
            contador=1;
        }
    }

    }
    jugadas.pop_back();
    abrir.close();
    cout << "Partida cargada con exito" << endl;
}

void Tablero::guardarJugada(string mov)
{
    string guardar;
    int xIni;
    int yIni;

    if(mov[0] == 'a' || mov[0] == 'A')
        xIni = 0;
    else if(mov[0] == 'b' || mov[0] == 'B')
        xIni = 1;
    else if(mov[0] == 'c' || mov[0] == 'C')
        xIni = 2;
    else if(mov[0] == 'd' || mov[0] == 'D')
        xIni = 3;
    else if(mov[0] == 'e' || mov[0] == 'E')
        xIni = 4;
    else if(mov[0] == 'f' || mov[0] == 'F')
        xIni = 5;
    else if(mov[0] == 'g' || mov[0] == 'G')
        xIni = 6;
    else
        xIni = 7;

    yIni = (int)mov[1] - 48;

    guardar = tablero[yIni][xIni].getNombre() + " a " + mov[5] + mov[6];
    jugadas.push_back(guardar);
}

void Tablero::mostrarJugadas()
{
    vector<string>::iterator it;
    for(it = jugadas.begin(); it != jugadas.end(); it++)
    {
        cout << (*it) << endl;
    }
}

void Tablero::borrarUltimaJugada()
{
    vector<string>::iterator it;
    it = jugadas.end();
    jugadas.erase(it);
}

void Tablero::menuPpal()
{
    int opcion = 0;

    do
    {
    cout << "*======================================================*"<<endl;
    cout << "*                     Bienvenid@ a                     *"<<endl;
    cout << "*              Ajedrez por: Manuel Diaz                *"<<endl;
    cout << "*======================================================*"<<endl;
    cout << "*                                                      *"<<endl;
    cout << "*                   (1)Nuevo juego                     *"<<endl;
    cout << "*                   (2)Continuar Partida               *"<<endl;
    cout << "*                   (3)Guardar Partida                 *"<<endl;
    cout << "*                   (4)Cargar Partida                  *"<<endl;
    cout << "*                   (0)Salir                           *"<<endl;
    cout << "*                                                      *"<<endl;
    cout << "*======================================================*"<<endl<<endl;
    cout << "Su opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
            {
                nuevaPartida(); //Investigar como creo el nuevo objeto y trabajo desde el
                cin.ignore();
                jugar();
                break;
            }
            case 2:
                cin.ignore();
                jugar();
                break;
            case 3:
                guardarPartida();
                break;
            case 4:
                cargarPartida();
                break;
            default:
                if (opcion != 0)
                    cout << "=== Opcion no valida ===" << endl;
        }

    } while (opcion != 0);
}
