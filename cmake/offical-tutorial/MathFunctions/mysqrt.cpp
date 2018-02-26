#include "MathFunctions.h"
#include "TutorialConfig.h"
#include "Table.h"
#include <stdio.h>

double mysqrt(double x) {
	double result;
#if defined(HAVE_LOG) && defined(HAVE_EXP)
	result = exp(log(x) * 0.5);
	fprintf(stdout, "Computing sqrt of %g to be %g using log\n", x, result);
#else
	double delta;
	result = x;

	if (x >= 1 && x < 10) {
		result = sqrtTable[static_cast<int>(x)];
		fprintf(stdout, "Sqrt from table: %g\n", result);
	}
	int i{0};
	for (; i < 10; ++i) {
		if (result <= 0) {
			result = 0.1;
		}
		delta = x - (result * result);
		result += 0.5 * delta / result;
		fprintf(stdout, "Computing sqrt of %g to be %g\n", x, result);
	}
#endif
	return result;
}
