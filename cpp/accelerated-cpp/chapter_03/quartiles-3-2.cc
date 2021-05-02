#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::string;

typedef vector<double>::size_type vec_sz;
vec_sz findMidPoint(vec_sz start, vec_sz end);;
void printQuarter(string name, vec_sz start, vec_sz end, vector<double> vector);

int main() {

  cout << "Please enter a set of at least 4 numbers followed by EOF:" << endl;
  vector<double> values {};
  double x {0};
  while(cin >> x) {
    values.push_back(x);
  }
  sort(values.begin(), values.end());


  vec_sz size = values.size();
  vec_sz mid = findMidPoint(0, size);
  vec_sz lowerQuarter = findMidPoint(0, mid);
  vec_sz upperQuarter = findMidPoint(mid, size);

  cout << "size: " << size
    << "mid: " << mid
    << "lowerQuarter: " << lowerQuarter
    << "upperQuarter: " << upperQuarter << endl;

  printQuarter("lowestQuarter", 0, lowerQuarter, values);
  printQuarter("lowMidQuarter", lowerQuarter, mid, values);
  printQuarter("upperMidQuarter", mid, upperQuarter, values);
  printQuarter("uppest... America explain! Quarter", upperQuarter, size, values);
}


vec_sz findMidPoint(vec_sz start, vec_sz end) {
  return (end - start) / 2 + start;
}

void printQuarter(string name, vec_sz start, vec_sz end, vector<double> vector) {
  cout << "Printing values in " << name << " quarter" << endl;
  for(vec_sz i = start; i < end; i++)
    cout << vector[i];

  cout << endl;
}
