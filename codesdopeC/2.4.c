#include <stdio.h>

int main() {
	float num;
	printf("Give a float: ");
	scanf("%f", &num);
	printf("%f typecasted to an int gives %d\n", num, (int)num);
	return 0;
}
