#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct st {
	char *str; // ���ڿ� ����
	int cnt; // ���� �� ����
}ST;

int main() {
	ST *l, *p, *q, tmpst;
	int n, i, len, cnt;
	char tmp[101];

	scanf("%d", &n);

	l = (ST *)malloc(n * sizeof(ST));//�Է¹��� n�� ���� �����Ҵ�

	for (p = l; p < l + n; p++) {
		scanf("%s", tmp);//�ӽ÷� �Է¹ޱ�
		p->str = (char*)malloc((strlen(tmp) + 1) * sizeof(char));//å �̸� str �����Ҵ�
		strcpy(p->str, tmp);//�����Ҵ� �����ſ� �ֱ�
	}

	for (p = l; p < l + n; p++) {
		len = strlen(p->str);//å�̸��� ����
		cnt = 0;//�ʱ�ȭ
		for (i = 0; i < len; i++) {//������ �ƴ϶��
			if (p->str[i] != 'A' && p->str[i] != 'a' && p->str[i] != 'E' && p->str[i] != 'e' && p->str[i] != 'I' && p->str[i] != 'i' && p->str[i] != 'O' && p->str[i] != 'o' && p->str[i] != 'U' && p->str[i] != 'u') {
				cnt++;//cnt����
			}
		}
		p->cnt = cnt;//�� ������ ����ü�� cnt�� �ֱ�
	}

	for (p = l + n; p >= l; p--) {//������ ���� ���� ���� ���ڿ����� ������������ ����, ���� ���� ������ �Էµ� ������� ����
		for (q = l; q < p - 1; q++) {
			if (q->cnt < (q + 1)->cnt) {//tmpst�� �̿��Ͽ� �ٲ���
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
		}
	}

	for (p = l; p < l + n; p++) {
		printf("%s\n", p->str);//���
	}

	for (p = l; p < l + n; p++) {//�Ҵ��� �޸� ����
		free(p->str);
	}
	free(l);//�Ҵ��� �޸� ����
}