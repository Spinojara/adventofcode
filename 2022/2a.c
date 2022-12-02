#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	time_t t = clock();
	FILE *file = fopen("2.txt", "r");
	char buffer[16];
	int a, b;
	int win;
	int total = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		a = buffer[0] - 'A';
		b = buffer[2] - 'X';
		win = 6 * (((b - a) == 1) || (a == 2 && b == 0)) + 3 * (b == a);
		total += win + b + 1;
	}
	printf("%i\n", total);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	return 0;
}
