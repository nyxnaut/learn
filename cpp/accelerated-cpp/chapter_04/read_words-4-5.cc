#include "read_words-4-5.h"

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::istream;

istream& read_words(istream& in, vector<string>& words) {
  if(in) {
    words.clear();
    string word;
    while (in >> word)
      words.push_back(word);
    in.clear();
  }
  return in;
}
