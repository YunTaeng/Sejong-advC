#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct student {
	char *studentName; // �л� �̸�
	char id[5]; // �л� �й�
	char *subjectName; // ���� �̸�
	double subjectScore; // ���� ����
}STUDENT;

int main() {
	int n, k;
	char tmp1[101], tmp2[101];
	STUDENT *st, *p, *q, tmpst;
	scanf("%d", &n);

	st = (STUDENT *)malloc(n * sizeof(STUDENT));//�Է¹��� n�� ���� ����ü �����Ҵ�

	for (p = st; p < st + n; p++) {
		scanf("%s %s %s %lf", tmp1, p->id, tmp2, &p->subjectScore);//�л����� �Է¹ޱ�
		p->studentName = (char*)malloc((strlen(tmp1) + 1) * sizeof(char));//�л��̸� �����Ҵ�
		strcpy(p->studentName, tmp1);//�����Ҵ� �����ſ� �ֱ�
		p->subjectName = (char*)malloc((strlen(tmp2) + 1) * sizeof(char));//�����̸� �����Ҵ�
		strcpy(p->subjectName, tmp2);//�����Ҵ� �����ſ� �ֱ�
	}

	scanf("%d", &k);

	for (p = st + n; p >= st; p--) {
		for (q = st; q < p - 1; q++) {
			if (q->subjectScore < (q + 1)->subjectScore) {
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
		}
	}

	p = st + k - 1;
	printf("%s %s %s %.2lf", p->studentName, p->id, p->subjectName, p->subjectScore);

	for (p = st; p < st + n; p++) {//�Ҵ��� �޸� ����
		free(p->studentName);
		free(p->subjectName);
	}
	free(st);//�Ҵ��� �޸� ����
}