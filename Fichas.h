/*
  Archivo: Fichas.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831 - Juan Camargo COD 1741510
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co - camargo.juan@correounivalle.edu.co
  Fecha creacion: 2018-05-14
  Fecha ultima modificacion: 2018-06-25
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad: Clase que representa una ficha del ajedrez
// Colaboracion: ninguna

#ifndef _FICHAS_
#define _FICHAS_

#include <string>
#include <iostream>

using namespace std;


class Fichas{
private:
    int id;
    char idChar;
    string unicode;
    string nombre;
    int jugador;

public:
    Fichas();
    Fichas(char idChar, string unicode, string nombre, int jugador);
    ~Fichas();
    void setId(int id);
    int getId();
    void setIdChar(char idChar);
    char getIdChar();
    void setUnicode(string unicode);
    string getUnicode();
    void setNombre(string nombre);
    string getNombre();
    void setJugador(int jugador);
    int getJugador();
    
    
};

#endif