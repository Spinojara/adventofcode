#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _strlen(char *s) {
	int i;
	for (i = 0; s[i] && s[i] != '\n'; i++);
	return i;
}

int shared_item(char *s) {
	int len = _strlen(s) / 2;
	for (int i = 0; i < len; i++)
		for (int j = len; j < 2 * len; j++)
			if (s[i] == s[j])
				return s[i];
	return 0;
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("3.txt", "r");
	char buffer[4096];
	int item;
	int total = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		item = shared_item(buffer);
		if ('a' <= item && item <= 'z')
			item -= 'a' - 1;
		else
			item -= 'A' - ('z' - 'a' + 2);
		total += item;
	}
	printf("%i\n", total);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	fclose(file);
	return 0;
}
