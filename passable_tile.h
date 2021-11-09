#ifndef PASSABLE_TILE_H
#define PASSABLE_TILE_H

#include "tile.h"
#include "material.h"

class PassableTile : public Tile {
private:
    Material* material_contained;


public:

    //PRE:-
    //POS: Created a PassableTile object and points the pointer 'material_contained' to null   
    PassableTile();

    //PRE:-
    //POS: Destroys PassableTile object and free memory.    
    ~PassableTile();

    //PRE:-
    //POS: Assign 'material' to 'material_contained'.
    void add_material(Material* material);

    //PRE:-
    //POS: Remove Material object and points pointer 'material_contained' to null. 
    void remove_material();

    //PRE:-
    //POS: Informs on screen what type of tile it is and if it is empty, otherwise it shows material type 
    //     it contains.
    void show();

    //PRE:-
    //POS: Return true if 'material_contained' is empty, false otherwise.
    bool tile_empty();

    //PRE:-
    //POS: Returns 'EMPTY' if 'material_contained' is empty and OCCUPIED if not.
    string state_of_tile();

    //PRE:-
    //POS: Returns what material type contains.
    string get_value();

    //PRE:-
    //POS: Returns what is a 'PASSABLE' tile.
    string get_tile_class();

};

#endif // PASSABLE_TILE_H
