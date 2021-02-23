#include <string>
#include <iostream>


int main()
{
  // s is defined in its own local context (denoted by {}) and no longer exists after the closing }. Therefore safe to redefine
  { const std::string s = "a string";
    std::cout << s << std::endl; }
  { const std::string s = "another string";
    std::cout << s << std::endl;}

  return 0;
}
