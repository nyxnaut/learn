#include "Student_info-4-6.h"

#include <iostream>
#include <vector>

#include "grade-4-6.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}

istream& read(istream& in, Student_info& student) {
  double midterm, finalExam;
  vector<double> homework;

  in >> student.name >> midterm >> finalExam;
  read_hw(in, homework);


  if (homework.size() > 0)
    student.grade = grade(midterm, finalExam, homework);
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
