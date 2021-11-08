#include "empty_passable_tiles.h"

EmptyPassableTiles::EmptyPassableTiles() {

  passable_tiles = new List<EmptyTile>;
  total_of_tiles = 0;

}


void EmptyPassableTiles::add_empty_tile(int x_coordinate, int y_coordinate) {

  EmptyTile* new_tile = new EmptyTile{x_coordinate, y_coordinate};

  passable_tiles->add_node(new_tile);

  total_of_tiles++;

}

void EmptyPassableTiles::get_random_tile() {

  srand ((unsigned int)time(NULL));

  int random_tile = rand() % total_of_tiles;

  passable_tiles->reset_current_node();

  for (int i = 0; i < random_tile; i++) {

    passable_tiles->next_node();

  }

}


int EmptyPassableTiles::get_target_tile_x_coordinate() {

  return passable_tiles->get_current_value()->x_coordinate;

}

int EmptyPassableTiles::get_target_tile_y_coordinate() {

    return passable_tiles->get_current_value()->y_coordinate;
}

void EmptyPassableTiles::delete_target_tile() {

  passable_tiles->delete_current_node();

}

EmptyPassableTiles::~EmptyPassableTiles() {

  delete passable_tiles;
  
}
