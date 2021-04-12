#include <iostream>

int factorial(int num);

int main() {
	std::cout << factorial(10) << std::endl;
	return 0;
}

int factorial(int num) {
	if (num == 1)
		return 1;
	return num * factorial(num - 1);
}
