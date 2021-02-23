#include <string>
#include <iostream>

// 1-6 What happens if you give it two names?
// Expected:
// The cin buffer is never flushed, and cin reads to next whitespace
// Only the first name will be displayed after the first prompt, then after entering a second (unused) name
// you will see the last name of the first entry displayed
//
// Actual:
// I didn't think about the fact that cin would not bother reading another value at all. I thought the prompt would block for a second name unused
// but actually it just read the next value from cin and continued
int main() {

  // write to buffer
  std::cout << "What is your name? ";
  std::string name;
  // flush buffer and read input to name
  std::cin >> name;
  // writes to buffer:
  // Hello, {name}\n And what is yours?
  std::cout << "Hello, " << name
    << std::endl << "And what is yours? ";
  // flushes buffer and overwrites the name
  std::cin >> name;

  // writes to buffer:
  // Hello, {name}; nice to meet you too!
  std::cout << "Hello, " << name
    << "; nice to meet you too!" << std::endl;
  return 0;
}
