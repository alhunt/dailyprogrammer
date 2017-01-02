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
	char *day = fday(1);
	int cmp = strcmp(day, "1 Partridge in a Pear Tree");
	mu_assert(!cmp, "Incorrect first day gift");
	free(day);

	day = fday(2);
	cmp = strcmp(day, "2 Turtle Doves");
	mu_assert(!cmp, "Incorrect second day gift");
	free(day);

	day = fday(3);
	cmp = strcmp(day, "3 French Hens");
	mu_assert(!cmp, "Incorrect third day gift");
	free(day);

	day = fday(4);
	cmp = strcmp(day, "4 Calling Birds");
	mu_assert(!cmp, "Incorrect fourth day gift");
	free(day);

	day = fday(5);
	cmp = strcmp(day, "5 Golden Rings");
	mu_assert(!cmp, "Incorrect fifth day gift");
	free(day);

	day = fday(6);
	cmp = strcmp(day, "6 Geese a Laying");
	mu_assert(!cmp, "Incorrect sixth day gift");
	free(day);

	day = fday(7);
	cmp = strcmp(day, "7 Swans a Swimming");
	mu_assert(!cmp, "Incorrect seventh day gift");
	free(day);

	day = fday(8);
	cmp = strcmp(day, "8 Maids a Milking");
	mu_assert(!cmp, "Incorrect eighth day gift");
	free(day);

	day = fday(9);
	cmp = strcmp(day, "9 Ladies Dancing");
	mu_assert(!cmp, "Incorrect ninth day gift");
	free(day);

	day = fday(10);
	cmp = strcmp(day, "10 Lords a Leaping");
	mu_assert(!cmp, "Incorrect tenth day gift");
	free(day);

	day = fday(11);
	cmp = strcmp(day, "11 Pipers Piping");
	mu_assert(!cmp, "Incorrect eleventh day gift");
	free(day);

	day = fday(12);
	cmp = strcmp(day, "12 Drummers Drumming");
	mu_assert(!cmp, "Incorrect twelfth day gift");
	free(day);
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
