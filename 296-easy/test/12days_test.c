#include "minunit.h"
#include "12days.h"
#include <string.h>
#include <stdlib.h>

MU_TEST(test_opening) {
	char *open = fopening(1);

	int cmp = strcmp(open, "On the first day of Christmas\n"
			       "my true love sent to me:");
	mu_assert(!cmp, "Incorrect first day opening");
	free(open);

	open = fopening(6);
	cmp = strcmp(open, "On the sixth day of Christmas\n"
			   "my true love sent to me:");
	mu_assert(!cmp, "Incorrect sixth day opening");
	free(open);

	open = fopening(12);
	cmp = strcmp(open, "On the twelfth day of Christmas\n"
			   "my true love sent to me:");
	mu_assert(!cmp, "Incorrect twelfth day opening");
	free(open);
}

MU_TEST(test_days) {
	mu_assert(fday(1) == "1 Partridge in a pear tree",
			"Incorrect first day gift");

	mu_assert(fday(2) == "2 Turtle Doves",
			"Incorrect second day gift");

	mu_assert(fday(3) == "3 French Hens",
			"Incorrect third day gift");

	mu_assert(fday(4) == "4 Calling Birds",
			"Incorrect fourth day gift");

	mu_assert(fday(5) == "5 Golden Rings",
			"Incorrect fifth day gift");

	mu_assert(fday(6) == "6 Geese a Laying",
			"Incorrect sixth day gift");

	mu_assert(fday(7) == "7 Swans a Swimming",
			"Incorrect seventh day gift");

	mu_assert(fday(8) == "8 Maids a Milking",
			"Incorrect eighth day gift");

	mu_assert(fday(9) == "9 Ladies Dancing",
			"Incorrect ninth day gift");

	mu_assert(fday(10) == "10 Lords a Leaping",
			"Incorrect tenth day gift");

	mu_assert(fday(11) == "11 Pipers Piping",
			"Incorrect eleventh day gift");

	mu_assert(fday(12) == "12 Drummers Drumming",
			"Incorrect twelfth day gift");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_opening);
	MU_RUN_TEST(test_days);
}

int main(int argc, char* argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
