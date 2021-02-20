#include <stdio.h>

int main() {
  // a string literal can be assigned to a string type variable
  const std::string hello = "Hello";
  // a string literal can be added to a string, and + is left associative so you can chain add
  const std::string leftAssociativeOkay = hello + " world" + "!";

  const std::string noPlusWorksWithoutString = "odd syntax" " but okay";

  const std::string willNotCompile = "a literal" + " another";
}
