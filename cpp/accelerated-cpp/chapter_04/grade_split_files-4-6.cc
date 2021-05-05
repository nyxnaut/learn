#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Student_info-4-6.h"

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

  try {
    while(read(cin, student)){
      maxlen = max(maxlen, student.name.size());
      students.push_back(student);
    }
  } catch (domain_error e) {
    cout << e.what();
    return 1;
  }
  sort(students.begin(), students.end(), compare);

  for(auto& student : students) {
    cout << student.name << string(maxlen + 1 - student.name.size(), ' ');
    streamsize prec = cout.precision();
    cout << setprecision(3) << student.grade << setprecision(prec) << endl;
  }

  return 0;
}

