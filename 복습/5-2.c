#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int wordcheck(char ch) { //숫자 0  /  영어 대소문자 1  / 마이너스  2 /그외 3

	if ('0' <= ch && ch <= '9') return 0;

	else if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z') return 1;

	else if (ch == '-') return 2;

	else return 3;
}

int main() {
	int arr[250], cnt = 0, *i, *j, *k, sum, maxsum, t, a, b;
	char tmp[101], *p;

	gets(tmp);

	for (p = tmp; *p != '\0'; p++) {
		if (wordcheck(*p) == 0) arr[cnt++] = (int)(*p - '0');

		else if (wordcheck(*p) == 1) arr[cnt++] = (int)*p;

		else if (wordcheck(*p) == 2) {
			if (wordcheck(*(p + 1)) == 0) {
				arr[cnt++] = (*(p + 1) - '0') *-1;
				p++;
			}
			else if (wordcheck(*(p + 1)) == 1) {
				arr[cnt++] = ((int)*(p + 1)) * -1;
				p++;
			}
		}
	}

	for (i = arr + cnt - 1; i >= arr; i--) {
		printf(" %d", *i);
	}

	maxsum = arr[0];
	a = 0;
	b = 0;

	for (t = 0; t < cnt; t++) {
		for (i = arr; i < arr + cnt; i++) {
			sum = 0;
			if (i + t > arr + cnt) continue;
			for (j = i; j <= i + t; j++) {
				sum += *j;
			}
			if (maxsum < sum) {
				maxsum = sum;;
				a = i - arr;
				b = a + t;
			}
		}
	}


	printf("\n%d\n%d %d", maxsum, a, b);
}
