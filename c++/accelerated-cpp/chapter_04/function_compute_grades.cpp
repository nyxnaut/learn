#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

void read_hw(istream& in, vector<double>& hw);

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const vector<double>& hw);
double median(vector<double> vec);

int main() {
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout <<  "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all your homework grades followed by EOF";

  vector<double> homework;

  read_hw(cin, homework);

  try {
    // run the code that could cause exception first so that the stream precision isn't a side
    // effect of an exception
    const double final_grade = grade(midterm, final, homework);

    // find the default stream precision
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) // set stream precision to 3
      << final_grade
      << setprecision(prec) << endl; // reset stream precision to default
  } catch (std::domain_error) {
    cout << endl << "You must enter your grades. Please try again" << endl;
    return 1;
  }

  return 0;
}

void read_hw(istream& in, vector<double>& hw) {
  if(in) {
    hw.clear();
    double x;
    while (in >> x)
      hw.push_back(x);
    in.clear();
  }
}

double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework) {
  return .2 * midterm + .4 * final + .4 * homework;
}

// calling this function copies the entire vector and attempts to sort the copy
// even if sorted
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if (size == 0)
    throw std::domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

