#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void shift(char arr[14]) {
	for (int i = 12; i >= 0; i--)
		arr[i + 1] = arr[i];
}

int check(char arr[14]) {
	for (int i = 0; i < 13; i++)
		for (int j = i + 1; j < 14; j++)
			if (arr[i] == arr[j] || arr[j] == '\0')
				return 0;
	return 1;
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("6.txt", "r");
	char mem[14] = { 0 };
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
