#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _strlen(char *s) {
	int i;
	for (i = 0; s[i] && s[i] != '\n'; i++);
	return i;
}

int shared_badge(char *s, char *t, char *u) {
	int lens = _strlen(s);
	int lent = _strlen(t);
	int lenu = _strlen(u);
	for (int i = 0; i < lens; i++)
		for (int j = 0; j < lent; j++)
			if (s[i] == t[j])
				for (int k = 0; k < lenu; k++)
					if (t[j] == u[k])
						return u[k];
	return 0;
}

int main(void) {
	time_t t = clock();
	FILE *file = fopen("3.txt", "r");
	char buffer[3][4096];
	int badge;
	int total = 0;
	while (fgets(buffer[0], sizeof(buffer[0]), file)) {
		badge = shared_badge(buffer[0],
				fgets(buffer[1], sizeof(buffer[1]), file),
				fgets(buffer[2], sizeof(buffer[2]), file));
		if ('a' <= badge && badge <= 'z')
			badge -= 'a' - 1;
		else
			badge -= 'A' - ('z' - 'a' + 2);
		total += badge;
	}
	printf("%i\n", total);
	printf("%f\n", (double)(clock() - t) / CLOCKS_PER_SEC);
	return 0;
}
