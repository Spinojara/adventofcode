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

void sort(int arr[3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (arr[i] < arr[j]) {
				int a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
	}
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("1.txt", "r");
	char buffer[16];
	int max[3] = { 0 };
	int current = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		if (buffer[0] == '\n') {
			if (current > max[2])
				max[2] = current;
			sort(max);
			current = 0;
		}
		else {
			current += stoi(buffer);
		}
	}
	printf("%i\n", max[0] + max[1] + max[2]);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	return 0;
}
