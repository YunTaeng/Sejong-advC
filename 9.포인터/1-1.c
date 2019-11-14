#include <stdio.h>
#pragma warning (disable:4996)

int maxmin(int a[]) {
	int *p, min, max;
	max = min = *a; //max와 min의 초기값은 a[0]이기 때문에 *a로 표현

	for (p = a;; p++) {
		if (*p != 0) { // 
			if (max < *p) max = *p; //a[]가 max보다 크면 max에 a[]를 대입
			if (min > *p) min = *p; //a[]가 min보다 작으면 min에 a[]를 대입
		}
		else break; //종료조건이 a[]가 0일때 이므로
	}
	return max - min;
}

int main() {
	int a[100], n, i, num, *p;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {//n회 반복
		p = a; //포인터p가 항상 a[0]부터 시작하도록
		do {
			scanf("%d", &num);
			*p = num;
			p++;
		} while (num != 0); //a[]가 0일떄 종료

		printf("%d\n", maxmin(a));//a[]를 maxmin 함수에 넣어 최댓값과 최솟값의 차이를 구함
	}

}