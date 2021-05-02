// really wishing we 'knew' hash tables existed for this one
// I can't think of a performant way to do this with just vector so
// instead I'm going to just scan the entire history of words each time.
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

typedef vector<string>::size_type s_sz;
typedef vector<s_sz>::size_type i_sz;

int main() {
  cout << "Write a bunch of words and we'll count word frequency: ";

  vector<string> words;
  vector<s_sz> frequencies;

  string input {};
  cin >> input;
  words.push_back(input);
  frequencies.push_back(1);

  while(cin >> input) {

    bool isNew = true;
    for(s_sz i = 0; i < words.size(); i++) {
      if (words[i].compare(input) == 0) {
        frequencies[i] += 1;
        isNew = false;
      }
    }
    if(isNew) {
      words.push_back(input);
      frequencies.push_back(1);
    }
  }
  cout << "Here are the word frequencies:\n"
    << "word" << "\tfrequency\n";
  for(s_sz i = 0; i < words.size(); i++)
    cout << words[i] << "\t" << frequencies[i] << "\n";
  cout << endl;
}
