#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[101], *tmp[10]; //�ִ���� 100�� ���ڿ�
	int numcnt, i, j, cnt = 0;
	double num[10];

	gets(str);//������ �����ϴ� ���ڿ� �Է¹ޱ�

	for (i = 0; str[i] != '\0'; i++) {//���� �����
		if (str[i] == ' ') {//������ ������ ������ ����� ��ĭ�� ������ ���
			for (j = i; str[j] != '\0'; j++) {
				str[j] = str[j + 1];
			}
		}
	}
	tmp[cnt] = str;//���ڸ� ��ȣ�� �������� tmp�� char���·� ����. tmp�� ó������ str�� �Ǿ�
	cnt++;

	for (i = 0; str[i] != '\0'; i++) {
		if ('0' > str[i] || str[i] > '9') {//str�� ���ڰ� �ƴҰ�� tmp�� ���� �迭�� ���� => ���ڰ� ��ȣ�� �������� �������� tmp�� ���� ����
			str[i] = '\0';
			tmp[cnt++] = &str[i + 1];
		}
	}
	numcnt = cnt;//��ȣ�� ���� ������ ���ڰ� ����� �޾Ƴ���

	for (i = 0; i < numcnt; i++) {//tmp�� �޾Ƴ��� char�迭�� �Ǽ��� �迭num�� �ֱ�
		num[i] = (double)atoi(tmp[i]);
	}

	for (i = 0; i < numcnt; i++) {

		printf(" %.0lf", num[i]);//���

	}
}