#include <stdio.h>

int main()
{
  int age = 10;
  int height = 72;

  printf("I am %d years old.\n", age);
  printf("I am %d inches tall.\n", height);

  // * allows dynamically formatting the width of the %d
  int fieldWidth = 8;
  printf("* in formatting: %*d\n", fieldWidth, 12);

  // c99 does not specify $ formats- comes from Single UNIX spec
  // every argument must be used, and every argument specifier must use $

  // we can flip the argument order if we choose
  printf("$ in formatting: %1$*2$d\n", 12, fieldWidth);
  // or repeat the same argument
  printf("$ repeat example: %2$d%2$d, %1$d\n", 12, fieldWidth);


  // Flag chars: # 0 - ' ' + and ' in Single UNIX Spec*
  
  return 0;
}
