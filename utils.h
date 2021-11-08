#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "constants.h"

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

#ifdef __APPLE__
#define CLR_SCREEN "clear"
#endif // __APPLE__


using namespace std;

string capitalize_word(string word);

string lowercase_word(string word);

bool is_numeric(string string_to_check);

bool ask_user_confirmation(string building_type);

#endif //UTILS_H
