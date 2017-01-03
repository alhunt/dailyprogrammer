#include "minunit.h"
#include "parentheses.h"
#include <string.h>

MU_TEST(test_remove_duplicates) {
	int cmp = strcmp(rem_dupes("((a))"), "(a)"); 
	mu_assert(!cmp, "failed to remove dupes from ((a))");

	cmp = strcmp(rem_dupes("((a((bc)(de)))f)"), "((a((bc)(de)))f)");
	mu_assert(!cmp, "((a((bc)(de)))f) contains no dupes to remove");

	cmp = strcmp(rem_dupes("(((zbcd)(((e)fg))))"), "((zbcd)((e)fg))");
	mu_assert(!cmp, "failed to remove dupes from (((zbcd)(((e)fg))))");

	cmp = strcmp(rem_dupes("ab((c))"), "ab(c)");
	mu_assert(!cmp, "failed to remove dupes from ab((c))");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_remove_duplicates);
}

int main(int argc, char* argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
