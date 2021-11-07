#include "utils.h"

//PRE: -
//POS: returns the word in lowercase.
string lowercase_word(string word){

  for (unsigned int i = 0; i < word.length(); i++) {

      word[i] = (char)tolower(word[i]);

  }

  return word;
}

//PRE: -
//POS: returns the word capitalized.
string capitalize_word(string word){

  word[0] = char(toupper(int(word[0])));

  return word;
}

bool is_numeric(string string_to_check) {

  for (int i = 0; i < int(string_to_check.length()); i++)

    if (isdigit(string_to_check[i]) == false)
       return false;

  return true;

}
