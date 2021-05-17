#include "grade.h"

#include <stdexcept>
#include <vector>

#include "median.h"
#include "Student_info.h"

using std::vector;
using std::domain_error;

bool fgrade(const Student_info& student) {
  return grade(student) < 60;
}

double grade(const Student_info& student) {
  return grade(student.midterm, student.final, student.homework);
}

double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework) {
  return .2 * midterm + .4 * final + .4 * homework;
}

