#include <stdio.h>

int main() {
	double l, w, area;
	printf("input the length then width of a rectangle:\n");
	scanf("%lf", &l);
	scanf("%lf", &w);
	area = l*w;
	printf("The rectangle's area is: %.2lf\n", area);
	return 0;
}
