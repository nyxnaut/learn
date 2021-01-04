#include <stdio.h>
#include <locale.h>

int main()
{
  unsigned int age = 10;
  int height = 72;

  printf("I am %d years old.\n", age);
  printf("I am %d inches tall.\n", height);

  // * allows dynamically formatting the width of the %d
  int fieldWidth = 8;
  printf("* in formatting: %*d\n", fieldWidth, 12);

  // c99 does not specify $ formats; it comes from the Single UNIX spec
  // every argument must be used, and every argument specifier must use $

  // we can flip the argument order if we choose
  printf("$ in formatting: %1$*2$d\n", 12, fieldWidth);
  // or repeat the same argument
  printf("$ repeat example: %2$d%2$d, %1$d\n", 12, fieldWidth);


  // Flag chars: # 0 - ' ' + (and ' in Single UNIX spec)

  // # Alternate Form
  // uint -> o, x, X  { unsigned octal, hexadecimal (lowercase/uppercase) }
  printf("# in octal formatting: %1$o -> %1$#o\n", age);
  printf("# in hex (l) formatting: %1$x -> %1$#x\n", age);
  printf("# in hex (u) formatting: %1$X -> %1$#X\n", age);

  // double -> a, A, e, E, f, F, g, G

  double thousands = 128273276145.273;
  int negative = -17230727;

  // ' Locale based thousands grouping numbers
  // double -> i, d, u, f, F, g, G
  setlocale(LC_ALL, "en_US");
  // i and d are the same for printf
  // in scanf %i will read hex and octal values if prefixed (0x, 0)
  printf("' in i integer formatting: %1$i -> %1$'i\n", negative);
  printf("' in d integer formatting: %1$d -> %1$'d\n", negative);
  // u reads given int as unsigned even if it is signed
  printf("' in u decimal formatting: %1$u -> %1$'u\n", age * negative);
  // f/F changes the case of 'inf'/'infinity' and 'nan'
  printf("' in f decimal formatting: %1$f -> %1$'f\n", thousands);
  printf("' in F decimal formatting: %1$f -> %1$'F\n", 1/0.0);
  // g/G converts between f style and e style decimals based on size
  printf("' in g decimal formatting: %1$f -> %1$'g\n", thousands);
  printf("' in G decimal formatting: %1$f -> %1$'G\n", thousands/1000000);
  
  return 0;
}
