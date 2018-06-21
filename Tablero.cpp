

#include "Tablero.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <windows.h>

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

    xBlanco = 4;
    yBlanco = 7;
    xNegro = 4;
    yNegro = 0;
}

Tablero::~Tablero()
{
    //MÃ©todo destructor
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
}

bool Tablero::veriMov(string mov)
{
    //a valid move has 7 characters
    if(mov.length() != 7)
    {
        return false;
    }
    //this basically just checkes each of the characters in the 3 sections of the move
    //format to ensure that the user has entered a valid range of inputs
    if(mov[0] != 'a' && mov[0] != 'b' && mov[0] != 'c' && mov[0] != 'd' &&
       mov[0] != 'e' && mov[0] != 'f' && mov[0] != 'g' && mov[0] != 'h' &&
       mov[0] != 'A' && mov[0] != 'B' && mov[0] != 'C' && mov[0] != 'D' &&
       mov[0] != 'E' && mov[0] != 'F' && mov[0] != 'G' && mov[0] != 'H')
    {

        return false;
    }

    //make sure the number of the board index is valid
    if(mov[1] != '0' && mov[1] != '1' && mov[1] != '2' && mov[1] != '3' &&
       mov[1] != '4' && mov[1] != '5' && mov[1] != '6' && mov[1] != '7'){

        return false;
    }

    //this is sort of unecessary...but I think it adds consistency to the game
    if(mov[3] != 'a' && mov[3] != 'A')
    {
        return false;
    }

    //valid ranger of letters for destination index
    if(mov[5] != 'a' && mov[5] != 'b' && mov[5] != 'c' && mov[5] != 'd' &&
       mov[5] != 'e' && mov[5] != 'f' && mov[5] != 'g' && mov[5] != 'h' &&
       mov[5] != 'A' && mov[5] != 'B' && mov[5] != 'C' && mov[5] != 'D' &&
       mov[5] != 'E' && mov[5] != 'F' && mov[5] != 'G' && mov[5] != 'H')
    {
        return false;
    }

    //valid range of numbers for destination index
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

    //b5 a c6
    // mov[0] = b inicial(1,algo) final(algo,algo)
    // mov[1] = 5 inicial(1,5) final(algo,algo)
    // mov[5] = 2 inicial(1,5) final(2,algo)
    // mov[6] = 6 inicial(1,5) final(2,6)

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
    int xIni;
    int yIni;
    int xFin;
    int yFin;


    if(mov[5] == 'a')
        xIni = 0;
    else if(mov[5] == 'b')
        xIni = 1;
    else if(mov[5] == 'c')
        xIni = 2;
    else if(mov[5] == 'd')
        xIni = 3;
    else if(mov[5] == 'e')
        xIni = 4;
    else if(mov[5] == 'f')
        xIni = 5;
    else if(mov[5] == 'g')
        xIni = 6;
    else
        xIni = 7;


    yFin = (int)mov[1] - 48;

    //b5 a c6
    // mov[0] = b inicial(1,algo) final(algo,algo)
    // mov[1] = 5 inicial(1,5) final(algo,algo)
    // mov[5] = 2 inicial(1,5) final(2,algo)
    // mov[6] = 6 inicial(1,5) final(2,6)

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

    yIni = (int)mov[6] - 48;

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
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            return false;
        }
        else if(yIni == 6 && tablero[yIni-1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            return false;
        }
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1) // corregir
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
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            return false;
        }
        else if(yIni == 1 && tablero[yIni+1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            return false;
        }
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1) // corregir
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

    //REY DE CUALQUIER JUGADOR
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

// revisar bien caballos y probar bien los peones

bool Tablero::validarMovimiento(string mov, int jugador)
{
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
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            cout << "Hay alguien ocupado esta casilla." << endl;
            return false;
        }
        else if(yIni == 6 && tablero[yIni-1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            cout << "Alguien obstruye el paso." << endl;
            return false;
        }
        else if(yIni == 6 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1) // corregir
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
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            cout << "Hay alguien ocupado esta casilla." << endl;
            return false;
        }
        else if(yIni == 1 && tablero[yIni+1][xIni].getIdChar()!= ' ' && abs(difFilas) ==2) // corregir
        {
            cout << "Alguien obstruye el paso." << endl;
            return false;
        }
        else if(yIni == 1 && tablero[yFin][xFin].getIdChar()!= ' ' && abs(difFilas) ==1) // corregir
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

    //REY DE CUALQUIER JUGADOR
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
        else if(difCol == 0 && difFilas > 0)
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
        else if(difCol == 0 && difFilas < 0)
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
        else if(difCol > 0 && difFilas == 0)
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
        else if(difCol < 0 && difFilas == 0)
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
        else if(difCol == 0 && difFilas > 0)
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
        else if(difCol == 0 && difFilas < 0)
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
        else if(difCol > 0 && difFilas == 0)
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
        else if(difCol < 0 && difFilas == 0)
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

// revisar bien caballos y probar bien los peones

bool Tablero::estoyEnJaque(int jugadorA,int opci)
{
    bool devolver = false;
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
                //cout << movim << endl;

                cout.setstate(ios_base::failbit);
                if(jugadorA==1)
                {

                    if(validarMovimiento(movim,2))
                    {
                        cout.clear();
                        cout << "La ficha " << tablero[i][j].getNombre();
                        if(opci==0)
                            cout << " te tiene en jaque." << endl;
                        else
                            cout << " te tendria en jaque si haces este movimiento" << endl;
                        devolver = true;
                    }
                }
                else
                {
                    if(validarMovimiento(movim,1))
                    {
                        cout.clear();
                        cout << "La ficha " << tablero[i][j].getNombre();
                        if(opci==0)
                            cout << " te tiene en jaque." << endl;
                        else
                            cout << " te tendria en jaque si haces este movimiento" << endl;
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

                cout.setstate(ios_base::failbit);
                if(jugadorA==1)
                {

                    if(validarMovimiento(movim,2))
                    {
                        cout.clear();
                        if(!interponerEnJaque(tablero[i][j].getIdChar(),i,j,jugadorA))
                        {
                            cout << "Estas en jaque mate, has perdido." << endl;
                            devolver = true;
                        }
                    }
                }
                else
                {
                    if(validarMovimiento(movim,1))
                    {
                        cout.clear();
                        if(!interponerEnJaque(tablero[i][j].getIdChar(),i,j,jugadorA))
                        {
                            cout << "Estas en jaque mate, has perdido." << endl;
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

void Tablero::jugar()
{
    bool gameover=false;
    int jugadorActual=2;
    string jugada;

    while(!gameover)
    {
        bool movValido = false;
        impTablero();

        cout << "Turno para ";
        if(jugadorActual==1)
        {
            cout << "fichas blancas." << endl;
        }
        else
        {
            cout << "fichas negras." << endl;
        }

        if(estoyEnJaque(jugadorActual,0))
        {
            if(estoyEnJaqueMate(jugadorActual))
            {
                movValido=true;
                gameover=true;
            }
        }


        while(!movValido)
        {
            cout << "Introduzca su jugada con el siguiente formato (a5 a b7):";
            getline(cin, jugada);

            if(veriMov(jugada))
            {
                if(validarMovimiento(jugada,jugadorActual))
                {
                    moverFicha(jugada);
                    if(estoyEnJaque(jugadorActual,1))
                    {
                        devolverFicha(jugada);
                    }
                    else
                    {
                        movValido = true;
                    }
                }
            }
            else
            {
                cout << "Comprueba el formato del movimiento." << endl;
            }
        }
        Sleep(1000);
        if(jugadorActual==1)
        {
            jugadorActual=2;
        }
        else
        {
            jugadorActual=1;
        }

        //cout << "rey negro: Y:" << getYnegro() << " X:" << getXnegro() << endl;
        //cout << "rey blanco: Y:" << getYblanco() << " X:" << getXblanco() << endl;
    }
}

bool Tablero::interponerEnJaque(char tipoF, int yIni, int xIni, int jugadorA)
{
    int xFin;
    int yFin;
    if(jugadorA==1)
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

    //cout << "Diferencia Filas: " << difFilas << endl;
    //cout << "Diferencia Columnas: " << difCol << endl;

    //Cuando la que hace jaque es una torre
    if(tipoF=='t' || tipoF=='T')
    {
        if(difCol > 0 && difFilas == 0)
        {
            for(int i=xIni;i<xFin;i++)
            {
                for(int k=0;k<8;k++)
                {
                     for(int l=0;l<8;l++)
                     {
                         if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                         {
                             if(validarMovimiento(l,k,i,yIni,jugadorA))
                             {
                                 //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                //cout << x << " " << y << endl;

                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {

                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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

            //cout << "x:" << x << " y:" << y;
            while(y!=yFin)
            {
                //cout << y << " " << x << endl;
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {
                        //cout << " l:" << l << " k:" << k << " x:" << x << " y:" << y;
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            //cout << " l:" << l << " k:" << k << " x:" << x << " y:" << y << endl;
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " asdasd " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,x,y,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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

                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                        if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                        {
                            if(validarMovimiento(l,k,i,yIni,jugadorA))
                            {
                                //cout << k << " " << l << tablero[k][l].getNombre() << endl;
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
                if(tablero[k][l].getJugador()==jugadorA && (l!=xFin || k!=yFin))
                {
                    if(validarMovimiento(l,k,xIni,yIni,jugadorA))
                    {
                        //cout << k << " " << l << tablero[k][l].getNombre() << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
