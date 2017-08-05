#include <stdio.h>
#include <clmul.h>

#define INPUT_MAX 255

int main(int argc, char* argv[]) {
	char input[INPUT_MAX];
	int x, y, result;

	printf("Enter two integers to carryless multiply: ");
	fgets(input, INPUT_MAX, stdin);

	if (sscanf(input, "%d %d", &x, &y) == 2) {
		result = clmul(x, y);
		printf("%d@%d=%d\n",x,y,result);
	}
	else
		printf("Invalid input!\n");

	return 0;
}
