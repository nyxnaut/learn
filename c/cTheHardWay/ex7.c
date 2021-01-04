#include <stdio.h>

int main() {

  int distance = 100;
  float power = 2.345f;
  double superPower = 2792.1238;
  char initial = 'M';
  char firstName[] = "Will";
  char lastName[] = "Newell";

  long bugs = 1024L * 1024L * 1024L;

  printf("d, p, sp = %d, %f, %f\n", distance, power, superPower);
  printf("name: %s %c. %s\n", firstName, initial, lastName);
  printf("There are %ld bugs\n", bugs);

  char nullByte = '\0';
  int percentage = 100 * nullByte;

  printf("You should care %d%% about %c this file.\n", percentage, nullByte);
  
  return 0;
}
