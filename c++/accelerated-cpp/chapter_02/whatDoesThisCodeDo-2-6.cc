#include <iostream>


// What does the following code do?

// this code prints the numbers 1 - 10 in a vertical column to standard out
int main() {
	int i = 0; // allocate and initialize an int type variable 'i'
	while (i < 10) { // if conditional is true enter the block. Loop block until conditional is no longer true
		i += 1; // assign the value stored at i its own value incremented by 1
		std::cout << i << std::endl; // write the value of I to io stream then write a newline and flush the buffer
	} // check if i is still less than 10, if so jump to the top of the block
}

