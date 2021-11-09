#ifndef BUILDABLE_TILE_H
#define BUILDABLE_TILE_H

#include "tile.h"
#include "building.h"

class BuildableTile : public Tile {
private:
    Building* building_contained;

public:

    //PRE:-
    //POS: Created a BuildableTile object and points the pointer 'building_contained' to null   
    BuildableTile();

    //PRE:-
    //POS: Assign 'building' to 'building_contained'.
    void add_building(Building* building);

    //PRE:-
    //POS: Points pointer 'building_contained' to null. 
    void remove_building();

    //PRE:-
    //POS: Informs on screen what type of tile it is and if it is empty, otherwise it shows building type 
    //     it contains.
    void show();

    //PRE:-
    //POS: Return true if 'building_contained' is empty, false otherwise.
    bool tile_empty();

    //PRE:-
    //POS: Returns 'EMPTY' if 'building_contained' is empty and OCCUPIED if not.
    string state_of_tile();

    //PRE:-
    //POS: Returns what building type contains.
    string get_value();

    //PRE:-
    //POS: Returns what is a 'BULDABLE' tile.
    string get_tile_class();

};

#endif //BUILDABLE_TILE_H
