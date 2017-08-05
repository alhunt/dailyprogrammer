#include "clmul.h"

int clmul(int x, int y) {
	int result = 0;

	/* Think of the numbers in binary. Each bit is checked in 'x' and
	 * if it is 1 then we need to get the value of 'y' shifted that many
	 * bits XOR added to the result.
	*/
	for (int i = 0; x > 0; i++) {
		if (x & 1)
			result ^= y << i;
		x >>= 1;
	}

	return result;
}
