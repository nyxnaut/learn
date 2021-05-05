#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

int main() {
  vector<double> numbers;
  double number;
  while(cin >> number)
    numbers.push_back(number);

  number = 0.0;
  for(auto& num : numbers)
    number += num;

  cout << "The average of the provided values = " << number / numbers.size() << endl;
  return 0;
}
