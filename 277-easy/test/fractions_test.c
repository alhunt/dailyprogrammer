#include "minunit.h"
#include "fractions.h"

MU_TEST(test_minunit) {
	mu_assert(0, "No Tests!");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_minunit);
}

int main(int argc, char* argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
