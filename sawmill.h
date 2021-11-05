#ifndef SAWMILL_H
#define SAWMILL_H

#include "building.h"

class SawmillBuilding : public Building {
private:
    string building_type;
    int amount_material_provide;

public:


    //PRE:
    //POS:
    int quantity_provides_materials();
    
};

#endif // SAWMILL_H