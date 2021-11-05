#ifndef FACTORY_H
#define FACTORY_H

#include "building.h"

class Factory : public Building {

public:

    Factory(string, int, int);

    //PRE:
    //POS:
    int quantity_provides_materials();
};

#endif // FACTORY_H
