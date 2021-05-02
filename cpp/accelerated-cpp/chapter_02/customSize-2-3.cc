#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using size_type = std::string::size_type;


int main () {
  cout << "Please enter your first name: ";
  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";

  // number of blanks surrounding the greeting
  int padding {0};

  cout << "How many spaces of padding should we use?: ";
  cin >> padding;

  // 2 line of padding, + 1 for greeting + 2 for border
  const int rows = padding * 2 + 1 + 2;
  // size of input + 2 padding + 2 for border
  const size_type cols = greeting.size() + padding * 2 + 2;

  cout << endl;

  int r = 0;

  while (r != rows) {
    size_type c = 0;
    while(c != cols) {
      if (r == 0 || r == rows - 1 || c == 0 || c == cols -1) {
        cout << "*";
        ++c;
      } else {
        if (r == padding + 1 && c == padding + 1) {
          cout << greeting;
          c += greeting.size();
        } else {
          cout << " ";
          ++c;
        }
      }
    }
    cout << endl;
    ++r;
  }

  return 0;
}
