#include <stdio.h>
#include <stdlib.h>
#include <12days.h>

int main(int argc, char* argv[]) {
	int i, x;

	char *open = fopening(1);
	printf("%s\n", open);
	free(open);
	char *day = fday(1);
	printf("%s\n", day);
	free(day);

	for (i = 2; i <= 12; i++) {
		open = fopening(i);
		printf("\n%s\n", open);
		free(open);

		for (x = i; x > 1; x--) {
			day = fday(x);
			printf("%s\n", day);
			free(day);
		}

		day = fday(1);
		printf("and %s\n", day);
		free(day);
	}

	return 0;
}
