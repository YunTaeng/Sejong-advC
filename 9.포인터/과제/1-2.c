#include <stdio.h>
#pragma warning (disable:4996)

int *maxmin(int a[]) {
	int *p = a, min, max, gap, mingap, *mingapaddress, tmp;
	max = min = *a; //max�� min�� �ʱⰪ�� a[0]�̱� ������ *a�� ǥ��

	while (*++p != 0) {
		if (max < *p) max = *p; //a[]�� max���� ũ�� max�� a[]�� ����
		if (min > *p) min = *p; //a[]�� min���� ������ min�� a[]�� ����
	}

	gap = max - min; // �ִ밪�� �ּҰ��� ����

	mingap = (gap - *a) * (gap - *a); //mingap�� �ʱⰪ�� gap���� a[0]�� ���� ����
	mingapaddress = a; //mingapaddress�� �ʱⰪ�� a[0]�� �ּ�

	p = a;//�ʱ�ȭ�۾�
	mingapaddress = a;

	while (*++p != 0) {//�迭�� ������ �ִ밪�� �ּҰ��� ���̿� ���� ����� �迭�� ���Ҹ� ã��
		tmp = (gap - *p) * (gap - *p);
		if (tmp < mingap) {
			mingap = tmp;//�ִ밪�� �ּҰ��� ���̿� ���� ����� �迭�� ���Ұ� �ޱ�
			mingapaddress = p;//�ִ밪�� �ּҰ��� ���̿� ���� ����� �迭�� ������ �ּҰ� �ޱ�
		}
	}
	return mingapaddress;//�迭���� �ִ밪�� �ּҰ��� ���̿� ���� ����� �迭�� ���� �ּ� ����
}

int main() {
	int a[100], n, i, *p, *q;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {//nȸ �ݺ�
		p = a; //������p�� �׻� a[0]���� �����ϵ���
		scanf("%d", p);
		while (*p++ != 0) {//0�� �ޱ� ������ �Է¹ޱ�
			scanf("%d", p);
		}
		q = maxmin(a);//maxmin�Լ��� �̿��Ͽ� �ִ밪�� �ּҰ��� ���̿� ���� ����� �迭�� ������ �ּҰ� �˾Ƴ���
		printf("%d\n", *q);//a[]�� maxmin �Լ��� �־� �ִ񰪰� �ּڰ��� ���̸� ����
	}
}