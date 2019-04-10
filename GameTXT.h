//
// Created by MATEO on 26.03.2019.
//

#ifndef POINTER_POINTERGOL_GAMETXT_H
#define POINTER_POINTERGOL_GAMETXT_H

#include <windows.h>
#include "Game.h"
#include <ctime>

class GameTXT :public Game
{
public:
    explicit GameTXT(int _columns={}, int _rows={}) :Game(_rows, _columns) {};
    virtual ~GameTXT()=default;
    void view() final;
};

///////////////////////////////////////// FUNCTIONS /////////////////////////////////////////


void GameTXT::view() {
    HANDLE hOut;
    int _width = (columns*2)+11;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    ////////////////// FIRST 6 ROWS
    for (int i = 0; i < 6; i++) {
        for(int j=0;j<_width;j++)
        {
            ////////////// RANDOMIZE STARS
            int rand = (std::rand()%3000)%100;
            if(rand ==0 || rand ==99) {
                SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
                std::cout << " ";
            }
            ////////////// NIGHT SKY
            else {
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << " ";
            }
        }
        std::cout<< "\n";
    }
    ////////////////// THE BANNER "GAME OF LIFE"
    if(columns>=8) {
        for (int i = 0; i < _width; i++) {
            if(i==0)
            {
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << "  ";
                i++;
            }
            else if(i==1 || i==2 || i==3 || i==4 || i==5 || i==6 || i==7
                || i==8 || i==9 || i==10 || i==11 || i==12 || i==13)
            {
                int rand = ((std::rand()%5000)%200);

                if(rand > 5 && rand <45) {
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED);
                    std::cout << "GAME OF LI E";
                    i = 13;
                }
                else if(rand>0 && rand <6) {
                    SetConsoleTextAttribute( hOut, BACKGROUND_RED | BACKGROUND_INTENSITY );;
                    std::cout << "BY  @  MATEO";
                    i = 13;
                }
                else{
                    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                    std::cout << "GAME OF LIFE";
                    i=13;
                }

            } else{
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << " ";
            }
        }
        std::cout <<"\n";
        //////////////////////////// BANNER CONSTRUCTION
        for(int i=0; i<_width;i++)
        {
            if(i==0){
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << "  ";
                i++;
            }
            else if(i==1 || i==2 || i==3 || i==4 || i==5 || i==6 || i==7
               || i==8 || i==9 || i==10 || i==11 || i==12 || i==13){
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout<< "|//| /| |//|";
                i=13;
            }
            else{
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << " ";
            }
        }
        std::cout<< "\n";
    }
    /////////////// BUILDING ROOF
    for(int i=0; i<_width;i++)
    {
        if(i==0){
            SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
            std::cout << " ";
        }
        else if(i==1){
            for(int j=i;j<((columns*2)+2); j++) {
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                std::cout << " ";
            }
            i=(columns*2)+1;
        }
        else{
            SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
            std::cout << " ";
        }
    }
    std::cout<< "\n";
    ////////////////// BUILDING AND no TREE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<_width+1;j++)
        {
            if(j==0){
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << " ";
            }
            else if(j==1){
                for(int k=0;k<columns;k++){
                    if(tab[i][k].getState()== false){
                        SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                        std::cout << " ";
                        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                        std::cout << " ";
                        j+=2;
                    }
                    else if(tab[i][k].getState()== true){
                        SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                        std::cout << " ";
                        SetConsoleTextAttribute(hOut,  BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
                        std::cout << " ";
                        j+=2;
                    }
                }
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                std::cout << " ";
                j++;
            } else{
                if(i+1==rows){
                    if(j==_width-3){
                        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_RED);
                        std::cout << " ";
                    }

                    else{
                        SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                        std::cout << " ";
                    }
                }
                else if(i+2==rows){
                    if(j==_width-4){
                        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
                        std::cout << "   ";
                        j+=2;
                    }
                    else{
                        SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                        std::cout << " ";
                    }
                }
                else{
                    SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                    std::cout << " ";
                }
            }
        }
        std::cout<< "\n";
        for(int j=0;j<_width-1;j++)
        {
            if(j==0 && i+1==rows) {
                SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                std::cout << " ";
            }
            else if(j==0){
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                std::cout << " ";
            }
            else if(j==1){
                for(int k=0;k<(columns*2)+1;k++){
                    SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    std::cout << " ";
                    j=k;
                }
            }
            else{
                if(i+1==rows){
                    if(j==_width-5){
                        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_RED);
                        std::cout << " ";
                    }
                    else{
                        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                        std::cout << " ";
                    }
                }
                else if(i+2==rows){
                    if(j==_width-7){
                        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
                        std::cout << "     ";
                        j+=4;
                    }
                    else{
                        SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                        std::cout << " ";
                    }
                }
                else{
                    SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
                    std::cout << " ";
                }
            }
        }
        std::cout<< "\n";
    }
    for(int i=0;i<_width;i++){
        SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
        std::cout << " ";
    }

    ///////////////////// OTHER ///////////////////////////
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    analysis();
}

#endif //POINTER_POINTERGOL_GAMETXT_H