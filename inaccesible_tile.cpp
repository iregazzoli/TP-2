#include "inaccesible_tile.h"

InaccesibleTile::InaccesibleTile(){}

void InaccesibleTile::show() {
    cout << "Consulted tile is " << BOLD_BLUE << INACCESIBLE << DEFAULT_COLOR;
}

string InaccesibleTile::get_tile_class() {

  return INACCESIBLE;

}
