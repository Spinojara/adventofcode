#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	time_t t = clock();
	FILE *file = fopen("2.txt", "r");
	char buffer[16];
	int a, b;
	int shape, total = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		a = buffer[0] - 'A';
		b = buffer[2] - 'X';
		shape = (a + (b - 1) + 3) % 3;
		total += shape + 1 + 3 * b;
	}
	printf("%i\n", total);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	return 0;
}
