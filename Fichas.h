

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