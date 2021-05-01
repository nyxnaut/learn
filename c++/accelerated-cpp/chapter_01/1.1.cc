#include <string>

int main() {
  // 1.0
  // a string literal can be assigned to a string type variable
  const std::string hello = "Hello";

  // 1.1
  // a string literal can be added to a string, and + is left associative so you can chain add
  const std::string leftAssociativeOkay = hello + " world" + "!";

  // 1.2
  // you can not add two literals directly
  // const std::string willNotCompile = "a literal" + " another"
  // nor right associate the values
  // const std::string rightAssociateNoGood = "Hello" + "World" + hello;

  // Note
  // but you can obviate the problem by dropping the +
  const std::string noPlusWorksWithoutString = "odd syntax" " but okay";
}
