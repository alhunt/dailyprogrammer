#include <stdio.h>
#include <fractions.h>

int main(int argc, char* argv[]) {
	int f[2];

	printf("Enter fraction: ");
	scanf("%d %d", &f[0], &f[1]);

	simplify(f);
	printf("%d %d\n", f[0], f[1]);

	return 0;
}
