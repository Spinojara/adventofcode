#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int stoi(char *s) {
	int i = 0;
	for (char *c = s; '0' <= *c && *c <= '9'; c++) {
		i = 10 * i;
		i += *c - '0';
	}
	return i;
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("1.txt", "r");
	char buffer[16];
	int max = 0;
	int current = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		if (buffer[0] == '\n') {
			if (current > max)
				max = current;
			current = 0;
		}
		else {
			current += stoi(buffer);
		}
	}
	printf("%i\n", max);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	fclose(file);
	return 0;
}
