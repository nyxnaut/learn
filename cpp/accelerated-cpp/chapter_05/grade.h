#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>

#include "Student_info.h"

bool fgrade(const Student_info& student);
double grade(const Student_info& student);
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);

#endif
