#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int a[10], b[10], n = 0, m = 0, *p = a, *q = b, i, k, tmp;

	do {//0을 받기 전까지 입력받기,0이외의 배열의 개수인 n도 센다
		scanf("%d", &k);
		if (k != 0) {
			*p = k;
			p++;
			n++;
		}
	} while (k != 0);

	do {//0을 받기 전까지 입력받기,0이외의 배열의 개수인 m도 센다
		scanf("%d", &k);
		if (k != 0) {
			*q = k;
			q++;
			m++;
		}
	} while (k != 0);

	//a는 내림차순으로 정렬, b는 오름차순으로 정렬하고, a 배열의 가장 작은 숫자(*(a + n - 1))와  b 배열의 가장 큰 숫자(*(b+m-1))를 바꾸는 것을  반복

	for (i = 0; i < n + m - 1; i++) {//최대 n+m-1번 돌리면 a,b배열의 모든 숫자가 정렬가능
		for (p = a; p < a + n; p++) { //내림차순으로 정렬
			for (q = a; q < a + n - 1; q++) {
				if (*q < *(q + 1)) {
					tmp = *q;
					*q = *(q + 1);
					*(q + 1) = tmp;
				}
			}
		}

		for (p = b; p < b + m; p++) { //오름차순으로 정렬
			for (q = b; q < b + m - 1; q++) {
				if (*q > *(q + 1)) {
					tmp = *q;
					*q = *(q + 1);
					*(q + 1) = tmp;
				}
			}
		}

		if (*(a + n - 1) < *(b + m - 1)) { //a 배열의 가장 작은 숫자(*(a + n - 1))와  b 배열의 가장 큰 숫자(*(b+m-1))를 바꾸는 것
			tmp = *(a + n - 1);
			*(a + n - 1) = *(b + m - 1);
			*(b + m - 1) = tmp;
		}
	}

	for (p = a; p < a + n; p++) {//a,b 배열 출력
		printf("%d ", *p);
	}
	printf("\n");
	for (p = b; p < b + m; p++) {
		printf("%d ", *p);
	}
}