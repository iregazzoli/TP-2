#ifndef MINE_H
#define MINE_H

#include "building.h"

class MineBuilding : public Building {
private:
    string building_type;
    int amount_material_provide;

public:
    
    //PRE:
    //POS:
    int quantity_provides_materials();
};

#endif // MINE_H