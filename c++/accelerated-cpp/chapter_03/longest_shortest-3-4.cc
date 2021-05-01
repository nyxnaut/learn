#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main () {
  cout << "Please input at least one string followed by EOF";

  string input;
  string::size_type min = input.max_size();
  string::size_type max = 0;

  while(cin >> input) {
    if (input.size() > max)
      max = input.size();
    if (input.size() < min)
      min = input.size();
  }

  cout << "The largest provided string was " << max << " characters" << endl;
  cout << "The smallest provided string was " << min << " characters" << endl;

  return 0;
}
