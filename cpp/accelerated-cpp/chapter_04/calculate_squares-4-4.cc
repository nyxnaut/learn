#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;

using std::string;
using std::to_string;

using std::setw;


int main() {
	double i = 10000.0;
	double power = i * i;
	string::size_type length = to_string(power).length() + 2;
	cout << setw(length) << "Number" << setw(length) << "Power" << endl;

	for(double i = 1; i < 10000; i++) {
		power = i * i;
		cout << setw(length) << i << setw(length) << power << endl;
	}
}

