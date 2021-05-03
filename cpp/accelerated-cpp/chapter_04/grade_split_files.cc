#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "median.h"
#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::domain_error;

using std::vector;
using std::string;

using std::sort;
using std::max;

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
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
      return 1;
    }
    cout << endl;
  }
  return 0;
}

