#include "fractions.h"

void simplify(int fraction[2]) {
	// Get Greatest Common Divisor
	int d = gcd(fraction[0], fraction[1]);

	// Use divisor to simplify fraction
	fraction[0] = fraction[0] / d;
	fraction[1] = fraction[1] / d;
}

int gcd(int x, int y) {
	// Use Euclidean algorithm to get GCD
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}
