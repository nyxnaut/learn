#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;

using std::string;
using std::to_string;

using std::setw;


int main() {
	int i = 100;
	int power = i * i;
	string::size_type length = to_string(power).length() + 2;
	cout << setw(length) << "Number" << setw(length) << "Power" << endl;

	for(; i > 0; i--) {
		power = i * i;
		cout << setw(length) << i << setw(length) << power << endl;
	}
}

