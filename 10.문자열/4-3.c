#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

void deletespace(char str[]) {//���� �����
	int i, cnt;
	do {
		for (i = 0, cnt = 0; i < strlen(str); i++) {
			if (str[i] == ' ') cnt++;//�������ŭ cnt�� ����
			if (cnt != 0) {
				str[i] = str[i + 1];//cnt�� 0�϶� ���� ������ ����
			}
		}
	} while (cnt != 0);//��ü �迭�� ������ ������ ���� �ݺ�
}


int main() {
	char str[101], oper[10], *tmp[10]; //�ִ���� 100�� ���ڿ�
	int  i, j, cnt = 0, opercnt = 0, numcnt = 0, k = 0;
	double num[11] = { 0 };

	gets(str);//������ �����ϴ� ���ڿ� �Է¹ޱ�

	deletespace(str);//���������

	tmp[numcnt] = str;//���ڸ� ��ȣ�� �������� tmp�� char���·� ����. tmp�� ó������ str�� �Ǿ�
	numcnt++;

	for (i = 0; str[i] != '\0'; i++) {
		if ('0' > str[i] || str[i] > '9') {//str�� ���ڰ� �ƴҰ�� tmp�� ���� �迭�� ���� => ���ڰ� ��ȣ�� �������� �������� tmp�� ���� ����
			oper[opercnt++] = str[i];
			str[i] = '\0';
			tmp[numcnt++] = &str[i + 1];
		}
	}
	for (i = 0; i < numcnt; i++) {//tmp�� �޾Ƴ��� char�迭�� �Ǽ��� �迭num�� �ֱ�
		num[i] = (double)atoi(tmp[i]);
	}

	for (k = 0; k <= opercnt; k++) {//*�� /�� ��� �����ؾ��ϹǷ� ���� ���
		for (i = 0; i <= opercnt; i++) {
			if (oper[i] == '*' || oper[i] == '/') {
				if (oper[i] == '*') num[i] *= num[i + 1];//*�϶�
				else if (oper[i] == '/') num[i] /= num[i + 1];//�϶�
				for (j = i + 1; num[j] != '\0'; j++) {//num[i]�� ����� ���(num[i] oper[i] num[i+1])�� �����ϸ� num[i+1]�� oper[i]�� ��������� ����
					num[j] = num[j + 1];//��ĭ�� ����
				}
				oper[i] = ' ';//oper[i]�� �������� �ٲپ�
				deletespace(oper);//��������� �Լ��� ���� �����
				break;//�극��ũ�� ����Ͽ� �ٽ� ó������ �Ȱ� ����
			}
		}
	}

	for (k = 0; k <= opercnt; k++) {//+��- �ǰ�� ���߿� ���
		for (i = 0; i <= opercnt; i++) {
			if (oper[i] == '+' || oper[i] == '-') {
				if (oper[i] == '+') num[i] += num[i + 1];//+�϶�
				else if (oper[i] == '-') num[i] -= num[i + 1];//--�ϋ�
				for (j = i + 1; num[j] != '\0'; j++) {
					num[j] = num[j + 1];
				}
				oper[i] = ' ';//oper[i]�� �������� �ٲپ�
				deletespace(oper);//��������� �Լ��� ���� �����
				break;//�극��ũ�� ����Ͽ� �ٽ� ó������ �Ȱ� ����
			}
		}
	}
	printf("%lf", num[0]);
}
