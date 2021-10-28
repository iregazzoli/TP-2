#include "square.h"

string Square::state_of_square() {
    if (square_empty)
        return "vacio";

    return "ocupado";
} 