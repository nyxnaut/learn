#include "Student_info.h"

#include <iostream>
#include <vector>

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
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

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> pass, fail;
  for(Student_info& student : students) {
    if (fgrade(student))
      fail.push_back(student);
    else
      pass.push_back(student);
  }
  students = pass;
  return fail;
}  
