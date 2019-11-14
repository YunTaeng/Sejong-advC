#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void upper(char *pstr) {
	char *p;
	for (p = pstr; *p; p++) {
		if ('A' <= *p&&*p <= 'Z') {
			printf("%c", *p);
		}
	}
}

void lower(char *pstr) {
	char *p;
	for (p = pstr; *p; p++) {
		if ('a' <= *p&&*p <= 'z') {
			printf("%c", *p);
		}
	}
}

int numcal(char *pstr) {
	char *p;
	int sum = 0;
	for (p = pstr; *p; p++) {
		if ('0' <= *p && *p <= '9') {
			sum *= 10;
			sum += *p - '0';
		}
	}
	return sum * 2;
}



int main() {
	char str[21], *p = str;
	int n;
	scanf("%d", &n);
	scanf("%s", str);

	upper(p);
	printf(" ");
	lower(p);
	printf(" ");
	printf("%d", numcal(p));
}