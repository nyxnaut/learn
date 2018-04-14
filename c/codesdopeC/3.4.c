#include <stdio.h>

int main() {
	int num = 0;
	while (num < 1000 || num >= 10000 ) {
		printf("please insert a 4 digit number: ");
		scanf("%d", &num);
	}
	num += 8;
	num /= 3;
	num %= 5;
	num *= 5;
	printf("Magic has made your number: %d\n", num);
	return 0;
}
