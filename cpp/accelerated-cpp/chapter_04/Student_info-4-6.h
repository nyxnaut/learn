#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
  Student_info() : grade(0) {}
  std::string name;
  double grade;
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read(std::istream& in, Student_info& student);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

#endif
