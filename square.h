#ifndef SQUARE_H
#define SQUARE_H
#include <fstream>
#include <iostream>
using namespace std;

class Square {
protected:
    bool square_empty;

public:
    
    Square(){};

    //PRE:
    //POST:
    virtual void show() = 0;

    string state_of_square();
};

#endif