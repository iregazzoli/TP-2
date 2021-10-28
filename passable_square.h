#ifndef PASSABLE_SQUARE_H
#define PASSABLE_SQUARE_H

#include "square.h"

class Passable_square : public Square {
private:
    string material_contained;
    int material_amount;

public:
    Passable_square();
    void show();
    void add_material(string material);
    void remove_material();
};

#endif // PASSABLE_SQUARE_H