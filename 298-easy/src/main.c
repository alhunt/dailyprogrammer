#include <stdio.h>
#include <string.h>
#include <parentheses.h>

int main(int argc, char* argv[]) {
	char dupes[255];
	int len;

	printf("Enter expression you wish to simplify: ");
	fgets(dupes, 255, stdin);
	len = strlen(dupes);
	if (len > 1) {
		rem_dupes(dupes, len);
		printf("%s\n", dupes);
	}

	return 0;
}
