#include <iostream>
#include <string>


int main () {
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;

  const std::string greeting = "Hello, " + name + "!";

  const std::string spaces(greeting.size(), ' ');
  const std::string spacer = "* " + spaces + " *";
  const std::string border(spacer.size(), '*');

  std::cout << std::endl;
  std::cout << border << std::endl;
  std::cout << spacer << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << spacer << std::endl;
  std::cout << border << std::endl;
  return 0;
}
