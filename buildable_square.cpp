#include "buildable_square.h"

Buildable_square::Buildable_square() {
    square_empty = true;
    type_building_contained = " ";
}

void Buildable_square::show() {
    if (square_empty) 
        cout << "Cansillero consultado es construible y se encuentra " << state_of_square() << endl;
    else
        cout << "Cansillero consultado es construible y se encuentra " << state_of_square() 
             << ", contiene el edificio: " << type_building_contained << endl;
}

void Buildable_square::build(string building) {
    square_empty = false;
    type_building_contained = building;
}