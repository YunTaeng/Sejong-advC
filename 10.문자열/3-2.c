#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char str1[100], str2[100], *q, *p, *r;
	int n, cnt = 0, flag1, flag2, lenb;

	gets(str1);
	gets(str2);
	lenb = strlen(str2);

	for (p = str1; *p; p++) {
		flag1 = 0;
		flag2 = 0;

		if ('a' <= *(p - 1) && *(p - 1) <= 'z' || 'A' <= *(p - 1) && *(p - 1) <= 'Z') flag2++;
		if ('a' <= *(p + lenb) && *(p + lenb) <= 'z' || 'A' <= *(p + lenb) && *(p + lenb) <= 'Z') flag2++;

		for (r = p, q = str2; *q; r++, q++) {
			if (*r == *q) flag1++;
		}

		if (flag1 == lenb && flag2 == 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
}