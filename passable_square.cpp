#include "passable_square.h"

Passable_square::Passable_square () {
    square_empty = true;
    material_contained = "";
    material_amount = 0;
}

void Passable_square::show() {
    if (square_empty) 
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_square() << endl;
    else
        cout << "Cansillero consultado es transitable y se encuentra " << state_of_square() 
             << ", contiene: " << material_contained << endl;
}

void Passable_square::add_material(string material) {
    material_contained = material;
    material_amount = 1;
    square_empty = false;
}

void Passable_square::remove_material() {
    square_empty = true;
    material_contained = "";
    material_amount = 0;
}