#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int checkrow(int **arr, int n, int m) {
	int i, j;
	int max = 0;
	int tmpmax = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				tmpmax++;

			}
			else tmpmax = 0;

			if (tmpmax > max) max = tmpmax;
		}
		tmpmax = 0;
	}

	return max;
}

int checkcol(int **arr, int n, int m) {
	int i, j;
	int max = 0;
	int tmpmax = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (arr[j][i] == 0) {
				tmpmax++;

			}
			else tmpmax = 0;

			if (tmpmax > max) max = tmpmax;
		}
		tmpmax = 0;
	}

	return max;
}





int main() {

	int i, j, n, m;
	int **arr;
	int x, y, z;
	int max = 0;
	scanf("%d %d", &m, &n);

	arr = (int **)calloc(m, sizeof(int *));

	for (i = 0; i < m; i++) {
		arr[i] = (int *)calloc(n, sizeof(int));
	}

	while (1) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0)break;
		arr[x][y] = z;
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}


	if (checkcol(arr, m, n) > checkrow(arr, m, n)) printf("%d", checkcol(arr, m, n));
	else printf("%d", checkrow(arr, m, n));

	for (i = 0; i < m; i++) {
		free(arr[i]);
	}
	free(arr);
}