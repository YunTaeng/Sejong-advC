#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char str[100], *word[3], *p;
	int n, i, cnt = 0;

	gets(str);

	word[cnt++] = &str;
	for (p = str; *p; p++) {
		if (*p == ' ') {
			*p = '\0';
			word[cnt++] = p + 1;
		}
	}
	if (strcmp(word[0], "add") == 0) {
		printf("%d", atoi(word[1]) + atoi(word[2]));
	}
	if (strcmp(word[0], "sub") == 0) {
		printf("%d", atoi(word[1]) - atoi(word[2]));
	}
	if (strcmp(word[0], "mul") == 0) {
		printf("%d", atoi(word[1]) * atoi(word[2]));
	}
	if (strcmp(word[0], "div") == 0) {
		printf("%d", atoi(word[1]) / atoi(word[2]));
	}
}