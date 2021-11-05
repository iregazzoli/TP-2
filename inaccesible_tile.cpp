#include "inaccesible_tile.h"

InaccesibleTile::InaccesibleTile(){}

void InaccesibleTile::show() {
    cout << "Cansillero consultado es inaccesible" << endl;
}

string InaccesibleTile::get_tile_class() {

  return INACCESIBLE;

}
