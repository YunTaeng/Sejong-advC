#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)


void input(int *p, int n) {
	int *i;

	for (i = p; i < p + n; i++) {
		scanf("%d", i);
	}
}

void output(int *p, int k) {
	int *i;
	for (i = p; i < p + k; i++) {
		printf(" %d", *i);
	}
}

int main() {
	int m, n, k, cnt = 0, min, i = 0, j = 0;
	int x[100], y[100], *p, *q;

	scanf("%d %d", &m, &n);

	if (m < n) min = m;
	else min = n;

	input(&x, m);
	input(&y, n);

	scanf("%d", &k);
	p = x;
	q = y;
	while (1) {
		if (i < m / k) {
			output(p, k);
			p += k;
			cnt += k;
			i++;
		}
		if (j < n / k) {
			output(q, k);
			q += k;
			cnt += k;
			j++;
		}
		if (cnt == m + n) break;
	}
}