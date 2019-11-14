#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int upper(int *arr) {
	int i = 1, flag, *p;
	while (1) {
		flag = 0;
		for (p = arr; p < arr + 6; p++) {
			if (i == *p) flag++;
		}
		if (flag == 0) return i;
		i++;
	}
}

int correct(int *arr) {
	int *p, *q, flag = 0;
	for (p = arr; p < arr + 6; p++) {
		for (q = p + 1; q < arr + 6; q++) {
			if (*p == *q) {
				flag = 1;
				*p = upper(arr);
			}
		}
	}
	return flag;
}

int main() {
	int ar[10], *p;

	for (p = ar; p < ar + 6; p++) {
		scanf("%d", p);
	}
	p = ar;
	printf("%d\n", correct(p));
	for (p = ar; p < ar + 6; p++) {
		printf("%d ", *p);
	}
}