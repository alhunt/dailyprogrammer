#include "minunit.h"
#include "parentheses.h"
#include <string.h>
#include <stdlib.h>

MU_TEST(test_seeking) {
	int pos = seek_fwd("(abc)", 5, 0);
	mu_assert(pos == 4, "failed to find ')' when seeking from 1st char");

	pos = seek_fwd("(abc)", 5, 2);
	mu_assert(pos == 4, "failed to find ')' when seeking from 4th char");

	pos = seek_fwd("((abc))", 7, 2);
	mu_assert(pos == 5, "failed to find ')' when multiple ')' exist");

	pos = seek_bk("(abc)", 5, 4);
	mu_assert(pos == 0, "failed to find '(' when seeking from 5th char");

	pos = seek_bk("(xyz(abc))", 10, 6);
	mu_assert(pos == 4, "failed to find '(' when multiple '(' exist");

	pos = seek_bk("(xyz(abc))", 10, 2);
	mu_assert(pos == 0, "failed to find '(' when starting between '('");
}

MU_TEST(test_remove_duplicates) {
	char dupes[] = "((a))";
	int dupes_len = strlen(dupes);
	rem_dupes(dupes, dupes_len);
	int cmp = strcmp(dupes, "(a)"); 
	mu_assert(!cmp, "failed to remove dupes from ((a))");

	sprintf(dupes, "((a((bc)(de)))f)");
	dupes_len = strlen(dupes);
	rem_dupes(dupes, dupes_len);
	cmp = strcmp(dupes, "((a((bc)(de)))f)");
	mu_assert(!cmp, "((a((bc)(de)))f) contains no dupes to remove");

	sprintf(dupes, "(((zbcd)(((e)fg))))");
	dupes_len = strlen(dupes);
	rem_dupes(dupes, dupes_len);
	cmp = strcmp(dupes, "((zbcd)((e)fg))");
	mu_assert(!cmp, "failed to remove dupes from (((zbcd)(((e)fg))))");

	sprintf(dupes, "ab((c))");
	dupes_len = strlen(dupes);
	rem_dupes(dupes, dupes_len);
	cmp = strcmp(dupes, "ab(c)");
	mu_assert(!cmp, "failed to remove dupes from ab((c))");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_seeking);
	MU_RUN_TEST(test_remove_duplicates);
}

int main(int argc, char* argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
