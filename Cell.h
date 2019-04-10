//
// Created by matid on 26.03.2019.
//

#ifndef POINTER_POINTERGOL_CELL_H
#define POINTER_POINTERGOL_CELL_H

class Cell
{
private:
    bool state;
public:
   bool getState();
    explicit Cell(bool _state=false) :state{_state} {};
    friend class Engine;
};

bool Cell::getState() {
    return state;
}

#endif //POINTER_POINTERGOL_CELL_H
