#include <stdio.h>
#pragma warning (disable:4996)

int *maxmin(int a[]) {
	int *p = a, min, max, gap, mingap, *mingapaddress, tmp;
	max = min = *a; //max와 min의 초기값은 a[0]이기 때문에 *a로 표현

	while (*++p != 0) {
		if (max < *p) max = *p; //a[]가 max보다 크면 max에 a[]를 대입
		if (min > *p) min = *p; //a[]가 min보다 작으면 min에 a[]를 대입
	}

	gap = max - min; // 최대값과 최소값의 차이

	mingap = (gap - *a) * (gap - *a); //mingap의 초기값은 gap에서 a[0]뺀 것의 제곱
	mingapaddress = a; //mingapaddress의 초기값은 a[0]의 주소

	p = a;//초기화작업
	mingapaddress = a;

	while (*++p != 0) {//배열을 훑으며 최대값과 최소값의 차이와 가장 가까운 배열의 원소를 찾기
		tmp = (gap - *p) * (gap - *p);
		if (tmp < mingap) {
			mingap = tmp;//최대값과 최소값의 차이와 가장 가까운 배열의 원소값 받기
			mingapaddress = p;//최대값과 최소값의 차이와 가장 가까운 배열의 원소의 주소값 받기
		}
	}
	return mingapaddress;//배열에서 최대값과 최소값의 차이와 가장 가까운 배열의 원소 주소 리턴
}

int main() {
	int a[100], n, i, *p, *q;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {//n회 반복
		p = a; //포인터p가 항상 a[0]부터 시작하도록
		scanf("%d", p);
		while (*p++ != 0) {//0을 받기 전까지 입력받기
			scanf("%d", p);
		}
		q = maxmin(a);//maxmin함수를 이용하여 최대값과 최소값의 차이와 가장 가까운 배열의 원소의 주소값 알아내기
		printf("%d\n", *q);//a[]를 maxmin 함수에 넣어 최댓값과 최솟값의 차이를 구함
	}
}