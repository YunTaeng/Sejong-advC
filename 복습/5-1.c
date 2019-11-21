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
	int arr[250], cnt = 0, *q, *r;
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

	for (q = arr + cnt - 1; q >= arr; q--) {
		printf(" %d", *q);
	}



}