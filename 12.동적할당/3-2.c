#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct subject {
	char *name; // ���� �̸�
	double score; // ���� ����
}SUB;

typedef struct student {
	char *name; // �л� �̸�
	char id[5]; // �л� �й�
	int numSubject; // ���� ����
	struct subject *psub; // ���� ����ü ������
	double avg; // ��� ������ ��� ����
}STUDENT;

void input_data(STUDENT *L) {//�л��� ������ �Է¹޴� �Լ�
	int i, cnt = 0, len, tmpid;
	char input[101], *p, tmpsc, **word;
	double avg = 0;

	gets(input);

	len = strlen(input);//���� len�� �޾Ƶα�
	for (i = 0; i < len; i++) {
		if (input[i] == ' ') {//�����̽����� ������ ���� ������� ��������.
			cnt++;
		}
	}
	L->numSubject = cnt / 2;//������� �����̽����� ������ 2�� �������� ������ ����
	word = (char **)malloc(sizeof(char *) * (cnt + 1));//word��� ������ ����Ʈ�迭
	cnt = 0;
	word[cnt++] = input;//������ġ
	for (i = 0; i < len; i++) {//�����̽��ٸ� �������� �ܾ ���� �ڵ�
		if (input[i] == ' ') {//�����̽��ٰ� ���� �� ���� ����
			input[i] = '\0';
			word[cnt++] = &input[i + 1];//�����̽��� ������ ���� �ܾ��� �����̹Ƿ�
		}
	}

	L->name = (char *)malloc(sizeof(char) * (strlen(word[0]) + 1));//��ó�� �ܾ�� �̸��̴� �޸𸮸� �����Ҵ����ص� ī���ϱ�
	strcpy(L->name, word[0]);
	strcpy(L->id, word[1]);//�ι�° �ܾ�� �й��̴�

	L->psub = (SUB *)malloc(sizeof(SUB) * L->numSubject);//������� ���� ����ü SUB �����Ҵ�

	for (i = 0; i < L->numSubject; i++) {
		L->psub[i].name = (char *)malloc(sizeof(char) * (strlen(word[2 * i + 2]) + 1));//�����̸� �����Ҵ��� �ֱ�
		strcpy(L->psub[i].name, word[2 * i + 2]);
		tmpsc = atoi(word[2 * i + 3]);
		L->psub[i].score = (double)tmpsc;//������ atoi�� double�� ���������ȯ���� �ֱ�
	}

	for (i = 0; i < L->numSubject; i++) {
		avg += L->psub[i].score;//������ �� ���ϱ�
	}
	L->avg = avg / L->numSubject;//����� ����/�����
}


int main() {
	int n, k, i;
	STUDENT *st, *p, *q, tmpst;
	SUB *sp, *max;

	scanf("%d", &n);//n�Է¹ޱ�
	getchar();

	st = (STUDENT *)malloc(n * sizeof(STUDENT));//�Է¹��� n�� ���� ����ü �����Ҵ�

	for (i = 0; i < n; i++) {
		input_data(&st[i]);
	}

	for (p = st + n; p >= st; p--) {//�����ϱ�
		for (q = st; q < p - 1; q++) {
			if (q->avg < (q + 1)->avg) {//��������� ���� �л����� �������� ����  
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
			else if (q->avg == (q + 1)->avg && strcmp(q->id, (q + 1)->id) > 0) {//��� ������ ���� �л��� ��쿡�� �й� ������ ����
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}

		}
	}

	scanf("%d", &k);//k�Է¹ޱ�
	p = st + k - 1;

	max = p->psub;//max �ʱ�ȭ
	for (sp = p->psub; sp < p->psub + p->numSubject; sp++) {
		if (sp->score > max->score) {
			max = sp;
		}
	}


	printf("%s %s %.2lf %s %.2lf", p->name, p->id, p->avg, max->name, max->score);

	for (p = st; p < st + n; p++) {//�Ҵ��� �޸� ����
		for (sp = p->psub; sp < p->psub + p->numSubject; sp++) {
			free(sp->name);
		}
		free(p->psub);
		free(p->name);
	}
	free(st);//�Ҵ��� �޸� ����
}