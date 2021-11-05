#ifndef FACTORY_H
#define FACTORY_H

#include "building.h"

class FactoryBuilding : public Building {
private:
    string building_type;
    int amount_material_provide;

public:
    
    //PRE:
    //POS:
    int quantity_provides_materials();
};

#endif // FACTORY_H