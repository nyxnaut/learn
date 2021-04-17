#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

using std::streamsize;
using std::setprecision;

typedef vector<string>::size_type vec_sz;

int main() {
  vector<string> names {};
  vector<double> finalGrades {};

  cout << "Please enter a students name: ";
  string name {};
  while(cin >> name) {
    cout << "Hello, " << name << "!\n";
    cout <<  "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades followed by the number -1\n";
    int count {0};
    double sum {0}, x {0};
    while (cin >> x && x != -1) {
      ++count;
      sum += x;
    }

    names.push_back(name);
    finalGrades.push_back(0.2 * midterm + .4 * final + .4 * sum / count);
    cout << "Please enter a students name or EOF to exit: ";
  }


  streamsize prec = cout.precision();
  for (vec_sz i {0}; i < names.size(); i++) {
    cout << names[i] << "'s final grade is " << setprecision(3)
      << finalGrades[i] << setprecision(prec) << endl;
  }
  return 0;
}

