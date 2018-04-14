#include <stdio.h>

int main() {
	int a;
	float b;
	char c;

	printf("Input an int: ");
	scanf("%d", &a);
	printf("Input a float: ");
	scanf("%f", &b);
	printf("Input a char: ");
	scanf(" %c", &c);
	printf("You entered %d, %f, %c\n", a, b, c);
	return 0;
}
