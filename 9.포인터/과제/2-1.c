#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char ar[10], list[10], *p, *q;
	int cnt = 0, flag, flag0 = 0;

	for (p = ar; p < ar + 6; p++) {
		scanf("%d", p);
	}

	for (p = ar; p < ar + 6; p++) {
		flag = 0;
		for (q = list; q < list + cnt; q++) {
			if (*q == *p) flag++;
		}

		if (flag == 0) {
			q = list;
			*(q + cnt) = *p;
			cnt++;
		}

	}

	for (q = list; q < list + cnt; q++) {
		flag = 0;
		for (p = ar; p < ar + 6; p++) {
			if (*p == *q) flag++;
		}
		if (flag >= 2) {
			printf("%d %d\n", *q, flag);
			flag0 = 1;
		}
	}
	if (flag0 == 0)printf("0");
}