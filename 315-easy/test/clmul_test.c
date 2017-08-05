#include "minunit.h"
#include "clmul.h"

MU_TEST(test_clmul) {
	mu_assert(clmul(1,2) == 2,      "Error: 1@2 should equal 2");
	mu_assert(clmul(9,0) == 0,      "Error: 9@0 should equal 0");
	mu_assert(clmul(6,1) == 6,      "Error: 6@1 should equal 6");
	mu_assert(clmul(3,3) == 5,      "Error: 3@3 should equal 5");
	mu_assert(clmul(2,5) == 10,     "Error: 2@5 should equal 10");
	mu_assert(clmul(7,9) == 63,     "Error: 7@9 should equal 63");
	mu_assert(clmul(13,11) == 127,  "Error: 13@11 should equal 127");
	mu_assert(clmul(5,17)  == 85,   "Error: 5@17 should equal 85");
	mu_assert(clmul(14,13) == 70,   "Error: 14@13 should equal 70");
	mu_assert(clmul(19,1)  == 19,   "Error: 19@1 should equal 19");
	mu_assert(clmul(63,63) == 1365, "Error: 63@63 should equal 1365");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_clmul);
}

int main(int argc, char* argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
