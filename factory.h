#ifndef FACTORY_H
#define FACTORY_H

#include "building.h"

class Factory : public Building {

public:
  
  //PRE:-
  //POS: Created Factory object.
  Factory(string, string, int, int);

  //PRE:-
  //POS: Returns amount of material factory produces.
  int produce_material();

};

#endif // FACTORY_H
