#include <iostream>

void printSquare(int size);
void printRectangle(int size);
void printTriangle(int size);
void printSolidBorder(int width);
void printFillBorder(int width);

int main() {
	int size;
	std::cin >> size;
	printSquare(size);
	printRectangle(size);
	printTriangle(size);
}

void printSquare(int size) {
	printSolidBorder(size);
	for (int i = 0; i < size - 2; i++)
			printFillBorder(size);
	printSolidBorder(size);
		
}

void printRectangle(int size) {
	const int width = size * 1.5;
	const int height = size;

	printSolidBorder(width);
	for (int i = 0; i < height - 2; i++)
			printFillBorder(width);
	printSolidBorder(width);
}

void printTriangle(int size) {
	printSolidBorder(1);
	printSolidBorder(2);
	for (int i = 3; i < size - 1; i++) {
		printFillBorder(i);
	}
	printSolidBorder(size);
}

void printFillBorder(int width) {
		std::cout << '*' << std::string(width - 2, ' ') << '*' << std::endl;
}

void printSolidBorder(int width) {
		std::cout << std::string(width, '*') << std::endl;
}
