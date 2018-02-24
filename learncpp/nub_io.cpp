#include <iostream>

int main() {
	int x = 4;
	std::cout << "I made a variable x and gave it the value: " << x << std::endl;
	std::cout << "but you seem nice so why don't you give me a value and i'll" <<
		" set it to x: ";
	std::cin >> x;
	std::cout << x << "? Nevermind I'm setting x back to 4.";
	x = 4;
	return 0;
}
