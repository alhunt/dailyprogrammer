#include "minunit.h"
#include "fractions.h"

MU_TEST(test_simplify) {
	int a[2] = {4, 8};
	simplify(a);
	mu_assert(a[0] == 1 && a[1] == 2,
		  "failed to simplify 4/8");

	a[0] = 1536;
	a[1] = 78360;
	simplify(a);
	mu_assert(a[0] == 64 && a[1] == 3265,
		  "failed to simplify 1536/78360");

	a[0] = 51478;
	a[1] = 5536;
	simplify(a);
	mu_assert(a[0] == 25739 && a[1] == 2768,
		  "failed to simplify 51478/5536");

	a[0] = 46410;
	a[1] = 119340;
	simplify(a);
	mu_assert(a[0] == 7 && a[1] == 18,
		  "failed to simplify 46410/119340");

	a[0] = 7673;
	a[1] = 4729;
	simplify(a);
	mu_assert(a[0] == 7673 && a[1] == 4729,
		  "failed to simplify 7673/4729");

	a[0] = 4096;
	a[1] = 1024;
	simplify(a);
	mu_assert(a[0] == 4 && a[1] == 1,
		  "failed to simplify 4096/1024");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_simplify);
}

int main(int argc, char* argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
