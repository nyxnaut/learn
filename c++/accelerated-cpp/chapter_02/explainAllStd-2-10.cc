#include <isotream>

int main() {
	int k = 0;
	while (k != 10) {
		using std::cout; // for the remainder of the block allows unqualified use of 'cout'
		cout << "*";
		++k;
	}
	// call the standard namespace's 'out output operator (<<) with the standard namespace's endl
	std::cout << std::endl; // std:: is required here because we have left the while block with the using directive
	return 0;
}
