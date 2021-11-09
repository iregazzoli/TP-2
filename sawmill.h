#ifndef SAWMILL_H
#define SAWMILL_H

#include "building.h"

class Sawmill: public Building {

public:

  //PRE:-
  //POS: Created a Sawmill object.
  Sawmill(string, string, int, int);

  //PRE:-
  //POS: Returns amount of material sawmill produces.
  int produce_material();

};

#endif // SAWMILL_H
