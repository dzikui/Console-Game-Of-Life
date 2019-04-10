//
// Created by matid on 26.03.2019.
//

#ifndef POINTER_POINTERGOL_ENGINE_H
#define POINTER_POINTERGOL_ENGINE_H

#include "Cell.h"

class Engine
{
    bool cellAnalysis(int _rows, int _columns) {bool _buff = tab[_rows][_columns].state; return _buff;};
    int nghborsAnalysis(int, int);
protected:
    int rows, columns;
    Cell **tab;
    Cell **tmpTab;
public:
    explicit Engine(int _rows={},int _columns={}) :rows{_rows}, columns{_columns} {};
    virtual ~Engine();
    //bool getState(int _rows, int _columns) {bool _buff = tab[_rows][_columns].state; return _buff;};
    void analysis();
};


///////////////////////////////////////// FUNCTIONS /////////////////////////////////////////

int Engine::nghborsAnalysis(int _rows, int _columns) {
    int _buff=0;
    if(_rows == 0){ /// dla rows ==0
        if(_columns == 0){
            _buff += int(cellAnalysis(_rows,_columns+1));
            _buff += int(cellAnalysis(_rows+1,_columns+1));
            _buff += int(cellAnalysis(_rows+1,_columns));
        }
        else if(_columns == columns-1){
            _buff += int(cellAnalysis(_rows,_columns-1));
            _buff += int(cellAnalysis(_rows+1,_columns-1));
            _buff += int(cellAnalysis(_rows+1,_columns));
        }
        else{
            _buff += int(cellAnalysis(_rows,_columns+1));
            _buff += int(cellAnalysis(_rows+1,_columns+1));
            _buff += int(cellAnalysis(_rows+1,_columns));
            _buff += int(cellAnalysis(_rows+1,_columns-1));
            _buff += int(cellAnalysis(_rows,_columns-1));
        }
    }
    else if(_columns==0){ ///dla columns ==0
        if(_rows != rows-1){
            _buff += int(cellAnalysis(_rows-1,_columns));
            _buff += int(cellAnalysis(_rows-1,_columns+1));
            _buff += int(cellAnalysis(_rows,_columns+1));
            _buff += int(cellAnalysis(_rows+1,_columns+1));
            _buff += int(cellAnalysis(_rows+1,_columns));
        }
        else if(_rows == rows-1){
            _buff += int(cellAnalysis(_rows-1,_columns));
            _buff += int(cellAnalysis(_rows-1,_columns+1));
            _buff += int(cellAnalysis(_rows,_columns+1));
        }
    }
    else if(_rows == rows-1){ /// dla rows == 9
        if(_columns != columns-1){
            _buff += int(cellAnalysis(_rows,_columns-1));
            _buff += int(cellAnalysis(_rows-1,_columns-1));
            _buff += int(cellAnalysis(_rows-1,_columns));
            _buff += int(cellAnalysis(_rows-1,_columns+1));
            _buff += int(cellAnalysis(_rows,_columns+1));
        }
        else if(_rows == rows-1){
            _buff += int(cellAnalysis(_rows,_columns-1));
            _buff += int(cellAnalysis(_rows-1,_columns-1));
            _buff += int(cellAnalysis(_rows-1,_columns));
        }
    }
    else if(_rows!=0 && _rows != rows-1 && _columns ==columns-1){
        _buff += int(cellAnalysis(_rows+1,_columns));
        _buff += int(cellAnalysis(_rows+1,_columns-1));
        _buff += int(cellAnalysis(_rows,_columns-1));
        _buff += int(cellAnalysis(_rows-1,_columns-1));
        _buff += int(cellAnalysis(_rows-1,_columns));
    }
    else{
        _buff += int(cellAnalysis(_rows-1,_columns-1));
        _buff += int(cellAnalysis(_rows-1,_columns));
        _buff += int(cellAnalysis(_rows-1,_columns+1));
        _buff += int(cellAnalysis(_rows,_columns+1));
        _buff += int(cellAnalysis(_rows+1,_columns+1));
        _buff += int(cellAnalysis(_rows+1,_columns));
        _buff += int(cellAnalysis(_rows+1,_columns-1));
        _buff += int(cellAnalysis(_rows,_columns-1));
    }
    return _buff;
}

Engine::~Engine() {
    for(int i=0; i<rows; i++)
    {
        delete tab[i];
        delete tmpTab[i];
    }
    delete [] tab;
    delete [] tmpTab;
}

void Engine::analysis() {
    tmpTab = new Cell*[rows];
    for (int i = 0; i < rows; i++) {
        tmpTab[i] = new Cell;
        for (int j = 0; j < columns; j++) {
            int judge = nghborsAnalysis(i,j);
            if(judge == 2 || judge == 3){
                if(judge==3 && cellAnalysis(i,j) == false){
                    tmpTab[i][j] = Cell(true);
                }
                else if(cellAnalysis(i,j) == true){
                    tmpTab[i][j] = Cell(true);
                }
                else{
                    tmpTab[i][j] = Cell(false);
                }
            }
            else{
                tmpTab[i][j] = Cell(false);
            }
        }
    }
    tab = tmpTab;
}

#endif //POINTER_POINTERGOL_ENGINE_H
