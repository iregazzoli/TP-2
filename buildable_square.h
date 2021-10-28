#ifndef BUILDABLE_SQUARE_H
#define BUILDABLE_SQUARE_H

#include "square.h"

class Buildable_square : public Square {
private:
    string type_building_contained;

public:
    Buildable_square();
    void show();
    void build(string building);
};

#endif // 