#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void shift(char arr[4]) {
	for (int i = 2; i >= 0; i--)
		arr[i + 1] = arr[i];
}

int check(char arr[4]) {
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			if (arr[i] == arr[j] || arr[j] == '\0')
				return 0;
	return 1;
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("6.txt", "r");
	char mem[4] = { 0 };
	int counter = 1;
	while ((mem[0] = getc(file)) != EOF) {
		if (check(mem))
			break;
		shift(mem);
		counter++;
	}
	printf("%i\n", counter);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	fclose(file);
	return 0;
}
