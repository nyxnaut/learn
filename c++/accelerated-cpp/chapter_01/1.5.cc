#include <string>
#include <iostream>

// x is outside of scope for the second cout statement. Move the first } to the end of the 9 line to fix
int main() {
  { const std::string s = "a string";
  { const std::string x = s + ", really";
    std::cout << s << std::endl;
    std::cout << x << std::endl; }
  }
  return 0;
}
