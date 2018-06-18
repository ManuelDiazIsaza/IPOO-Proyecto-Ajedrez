

#include "Fichas.h"
#include <string>
#include <iostream>

using namespace std;


Fichas::Fichas(){
    idChar = ' ';
    unicode = " ";
    nombre = " ";
    jugador = 0;
}

Fichas::Fichas(char idChar, string unicode, string nombre, int jugador){

    this -> idChar = idChar;
    this -> unicode = unicode;
    this -> nombre = nombre;
    this -> jugador = jugador;
}

Fichas::~Fichas()
{
    //MÃ©todo destructor
}

void Fichas::setId(int id)
{
    this -> id = id;
}

int Fichas::getId()
{
    return id;
}

void Fichas::setIdChar(char id)
{
    this -> idChar = idChar;
}

char Fichas::getIdChar()
{
    return idChar;
}

void Fichas::setUnicode(string unicode)
{
    this -> unicode = unicode;
}

string Fichas::getUnicode()
{
    return unicode;
}

void Fichas::setNombre(string nombre)
{
    this -> nombre = nombre;
}

string Fichas::getNombre()
{
    return nombre;
}

void Fichas::setJugador(int Jugador)
{
    this -> jugador = jugador;
}

int Fichas::getJugador()
{
    return jugador;
}
