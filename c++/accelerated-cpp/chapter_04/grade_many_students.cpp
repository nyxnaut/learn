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
using std::max;

struct Student_info {
  string name;
  double midterm, final;
  vector<double> homework;
};

istream& read(istream& in, Student_info& student);
istream& read_hw(istream& in, vector<double>& hw);

double grade(const Student_info& student);
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const vector<double>& hw);
double median(vector<double> vec);

bool compare(const Student_info& x, const Student_info& y);

int main() {
  vector<Student_info> students;
  Student_info student;
  string::size_type maxlen = 0;

  while(read(cin, student)){
    maxlen = max(maxlen, student.name.size());
    students.push_back(student);
  }

  sort(students.begin(), students.end(), compare);

  for(auto& student : students) {
    cout << student.name << string(maxlen + 1 - student.name.size(), ' ');
    try {
      double final_grade = grade(student);

      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec) << endl;
    } catch (std::domain_error e) {
      cout << e.what() << endl;
      return 1;
    }
  }
  return 0;
}

istream& read(istream& in, Student_info& student) {
  in >> student.name >> student.midterm >> student.final;
  read_hw(in, student.homework);
  return in;
}

istream& read_hw(istream& in, vector<double>& hw) {
  if(in) {
    hw.clear();
    double x;
    while (in >> x)
      hw.push_back(x);
    in.clear();
  }
  return in;
}

double grade(const Student_info& student) {
  return grade(student.midterm, student.final, student.homework);
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

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}
