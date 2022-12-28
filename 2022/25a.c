#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

long power(long a, int n) {
	if (!n)
		return 1;
	return a * power(a, n - 1);
}

long stoi(char *s) {
	/* new line character */
	int len = strlen(s);
	if (s[len - 1] == '\n')
		len--;
	long ret = 0;
	int index;
	for (int i = 0; i < len; i++) {
		index = len - (i + 1);
		switch (s[index]) {
		case '2':
		case '1':
		case '0':
			ret += (s[index] - '0') * power(5, i);
			break;
		case '-':
			ret -= power(5, i);
			break;
		case '=':
			ret -= 2 * power(5, i);
			break;
		default:
			return ret;
		}
	}
	return ret;
}

long mod5(long i) {
	i = i % 5;
	if (i < -2)
		return i + 5;
	if (i > 2)
		return i - 5;
	return i;
}

char *itos(char *s, long i) {
	int arr[256], len;
	for (int j = 0; j < 256; j++) {
		arr[j] = mod5(i);
		i -= arr[j];
		i /= 5;
		//printf("%i, %i\n", arr[j], i);
		if (i <= 0) {
			arr[j + 1] = 10;
			break;
		}
	}
	for (len = 0; arr[len] != 10; len++);
	//printf("%i\n", len);
	int index;
	for (int j = 0; j < len; j++) {
		index = len - (j + 1);
		switch (arr[index]) {
		case 2:
		case 1:
		case 0:
			s[j] = '0' + arr[index];
			break;
		case -1:
			s[j] = '-';
			break;
		case -2:
			s[j] = '=';
			break;
		}
	}
	s[len] = '\0';
	return s;
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("25.txt", "r");
	char buffer[256];
	long total = 0;
	while (fgets(buffer, sizeof(buffer), file)) {
		total += stoi(buffer);
		//printf("%i, %s\n", i, itos(buffer, i));

	}
	printf("%s\n", itos(buffer, total));
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	fclose(file);
	return 0;
}
