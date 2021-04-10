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
  const int padding = 1;

  // 2 line of padding, + 1 for greeting + 2 for border
  const int rows = padding * 2 + 1 + 2;
  // size of input + 2 padding + 2 for border
  const size_type cols = greeting.size() + padding * 2 + 2;

  const size_type innerSpacing = greeting.size() + 2;

  // separate output from input
  cout << endl;

  // write rows of output
  int r = 0;

  // invariant: we have written r rows so far
  while (r != rows) {
    size_type c = 0;
    while(c != cols) {
      if (r == 0 || r == rows - 1 || c == 0 || c == cols -1) {
        cout << "*";
        ++c;
      } else if (r == 1 || r == rows - 2) {
	 cout << string(innerSpacing, ' ');
	 c += innerSpacing;
      } else {
          cout << " " + greeting + " ";
          c += innerSpacing;
      }
    }
    // write row of output
    cout << endl;
    ++r; // update r so the invariant holds across the loop logic check
  }
  return 0;
}
