#include <iostream>
#include <string>

int main() {
	int x, y;
	std::cin >> x;
	std::cin >> y;

	std::string msg;
	msg = (x > y) ? "first is larger than second" : "second is larger than first";
	std::cout << msg << std::endl;
	return 0;
}
