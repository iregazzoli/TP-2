#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

const string DEFAULT_COLOR = "\e[0m";
const string BOLD_RED = "\e[1;31m";
const string BOLD_BLUE = "\e[1;34m";
const string BOLD_BLACK = "\e[1;30m";
const string BOLD_GREEN = "\e[1;32m";
const string BOLD_YELLOW = "\e[1;33m";
const string BOLD_CYAN = "\e[1;36m";
const string BOLD_VIOLET = "\e[1;35m";

const string DIVISORY_LINE = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";

const int WIDTH = 10;

const string MATERIAL_FILE_ROUTE = "materiales.txt";
const string BUILDING_FILE_ROUTE = "edificios.txt";
const string MAP_LOCATIONS_ROUTE = "ubicaciones.txt";
const string MAP_FILE_ROUTE = "mapa.txt";

const char LAKE = 'L';
const char TERRAIN = 'T';
const char ROAD = 'C';

#endif
