//
// Created by matid on 26.03.2019.
//


#ifndef POINTER_POINTERGOL_GAME_H
#define POINTER_POINTERGOL_GAME_H

#include <fstream>
#include "Engine.h"

class Game :public Engine
{
public:
    Game(int _rows={}, int _columns={}) :Engine(_rows, _columns) {};
    void start();
    virtual void view()=0;
    void setCursor(int x, int y);
    virtual ~Game()=default;
};

///////////////////////////////////////// FUNCTIONS /////////////////////////////////////////

void Game::setCursor(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void Game::start() {
    std::ifstream file;
    tab = new Cell*[rows];
    file.open("start.txt", std::ios::binary);
    if(file.is_open())
    {
        for(int i=0; i<rows; i++)
        {
            tab[i] = new Cell;
            for(int j=0;j<columns; j++)
            {
                bool _buffer;
                file >> _buffer;
                tab[i][j] = Cell(_buffer);
               // (tab[i][j]).showMe();
            }
            //std::cout << "\n";
        }
    }
    else
    {
        throw("Blad otwarcia pliku z danymi wejsciowymi.\n");
    }
    for(int i=0;i<2;i--)
    {
        view();
        Sleep(100);
        setCursor(0,0);
        if (i==-10)
        {
            system("cls");
        }
    }
}



#endif //POINTER_POINTERGOL_GAME_H
