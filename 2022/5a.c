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

void moveone(char arr[9][128], int a, int b) {
	int i, j;
	for (i = 127; arr[a][i] == ' '; i--);
	for (j = 0; arr[b][j] != ' '; j++);
	arr[b][j] = arr[a][i];
	arr[a][i] = ' ';
}

void move(char arr[9][128], int a, int b, int c) {
	for (int i = 0; i < c; i++)
		moveone(arr, a, b);
}

void print(char arr[9][128]) {
	for (int i = 32; i >= 0; i--) {
		for (int j = 0; j < 9; j++)
			printf("%c ", arr[j][i]);
		printf("\n");
	}
	printf("\n");
	for (int j = 0; j < 9; j++)
		printf("%i ", j);
	printf("\n");
}

void printresult(char arr[9][128]) {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; arr[i][j] != ' '; j++);
		printf("%c", arr[i][j - 1]);
	}
	printf("\n");
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("5.txt", "r");
	char buffer[128], *ptr;
	char arr[9][128];
	int a, b, c;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 128; j++)
			arr[i][j] = ' ';
	int line = 7;
	while (fgets(buffer, sizeof(buffer), file)) {
		if (line >= 0)
			for (int i = 0; i < 9; i++)
				arr[i][line] = buffer[4 * i + 1];
		if (line-- == -2)
			break;
	}
	while (fgets(buffer, sizeof(buffer), file)) {
		ptr = buffer + 5;
		c = stoi(ptr);
		ptr = ptr + 7 + (c >= 10);
		a = stoi(ptr);
		ptr = ptr + 5;
		b = stoi(ptr);
		move(arr, a - 1, b - 1, c);
	}
	printresult(arr);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	fclose(file);
	return 0;
}
