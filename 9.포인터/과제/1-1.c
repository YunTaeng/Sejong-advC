#include <stdio.h>
#pragma warning (disable:4996)

int maxmin(int a[]) {
	int *p, min, max;
	max = min = *a; //max�� min�� �ʱⰪ�� a[0]�̱� ������ *a�� ǥ��

	for (p = a;; p++) {
		if (*p != 0) { // 
			if (max < *p) max = *p; //a[]�� max���� ũ�� max�� a[]�� ����
			if (min > *p) min = *p; //a[]�� min���� ������ min�� a[]�� ����
		}
		else break; //���������� a[]�� 0�϶� �̹Ƿ�
	}
	return max - min;
}

int main() {
	int a[100], n, i, num, *p;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {//nȸ �ݺ�
		p = a; //������p�� �׻� a[0]���� �����ϵ���
		do {
			scanf("%d", &num);
			*p = num;
			p++;
		} while (num != 0); //a[]�� 0�ϋ� ����

		printf("%d\n", maxmin(a));//a[]�� maxmin �Լ��� �־� �ִ񰪰� �ּڰ��� ���̸� ����
	}

}