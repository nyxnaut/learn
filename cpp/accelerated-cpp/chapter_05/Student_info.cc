#include "Student_info.h"
#include "grade.h"

#include <iostream>
#include <vector>
#include <list>

using std::istream;
using std::vector;
using std::list;
typedef vector<Student_info>::size_type students_size;

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

list<Student_info> extract_fails(list<Student_info>& students) {
  list<Student_info> fail;
  list<Student_info>::iterator iter = students.begin();
  while(iter != students.end()) {
    if(fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else
      ++ iter;
  }
  return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::iterator iter = students.begin();
  while(iter != students.end()) {
    if(fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else
      ++ iter;
  }
  return fail;
}


vector<Student_info> even_worse_extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  students_size i = 0;
  while(i != students.size()) {
    if (fgrade(students[i])) {
      fail.push_back(students[i]);
      students.erase(students.begin() + i);
    } else {
      ++i;
    }
  }
  return fail;
}

// requires 2N storage because of the array copy, can do better
vector<Student_info> copy_extract_fails(vector<Student_info>& students) {
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
