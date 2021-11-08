#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "buildable_tile.h"
#include "building.h"
#include "passable_tile.h"
#include "inaccesible_tile.h"


class Map {

private:
  Tile*** map;

  int total_of_rows;
  int total_of_columns;

  Tile** current_tile;
  int current_row;
  int current_column;

public:
  Map(int rows, int columns);

  ~Map();

  void initialize();

  //PRE: (maybe clarify that the amount on letters on the, nah don't bother)
  //POS:
  void add_tile(char tile_type);

  void consult(int x_coordinate, int y_coordinate);

  string get_building_type(int x_coordinate, int y_coordinate);

  Tile* get_tile(int x_coordinate, int y_coordinate);

  bool tile_buildable(int x_coordinate, int y_coordinate);

  bool tile_passable(int x_coordinate, int y_coordinate);

  bool tile_empty(int x_coordinate, int y_coordinate);

  void add_building(Building* building, int x_coordinate, int y_coordinate);

  void remove_building(int x_coordinate, int y_coordinate);

  void add_material(Material* material, int x_coordinate, int y_coordinate);

  int get_rows();

  int get_columns();

  void show_map();

  void show_map_legend();
};


#endif
