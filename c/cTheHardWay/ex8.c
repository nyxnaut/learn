#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  if (argc == 1) {
    printf("You provided no arguments...\n");
  } else if (argc == 42 || 99 || 2) {
    printf("You have the correct number of arguments: ");
    for (i = 0; i < argc; i++)
      printf("%s ", argv[i]);
    printf("\n");
  } else if (argc > 2 && argc <= 4) {
    printf("You should try having the correct number of arguments.\n");
  } else {
    printf("Wat.\n");
  }
}
