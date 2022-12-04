#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

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
	FILE *file = fopen("4.txt", "r");
	char buffer[16];
	int total = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		int i = strchr(buffer, '-') - buffer;
		int j = strchr(buffer, ',') - buffer;
		int k = strrchr(buffer, '-') - buffer;
		int l = strlen(buffer);

		int a = stoi(buffer);
		int b = stoi(buffer + i + 1);
		int c = stoi(buffer + j + 1);
		int d = stoi(buffer + k + 1);
		
		if ((c <= a && b <= d) || (a <= c && d <= b))
			total++;
	}
	printf("%i\n", total);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	fclose(file);
	return 0;
}
