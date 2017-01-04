#include <stdio.h>
#include <string.h>
#include <parentheses.h>

int main(int argc, char* argv[]) {
	char dupes[255];

	printf("Enter expression you wish to simplify: ");
	scanf("%s", &dupes);
	rem_dupes(dupes, strlen(dupes));
	printf("%s\n", dupes);

	return 0;
}
