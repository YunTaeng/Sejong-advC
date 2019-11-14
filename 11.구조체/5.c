#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
//�����ͷ�Ǯ��
struct system {//�л����� ������ ������ ����ü ����
	char name[31];//�̸�
	char studentid[9];//�й�
	int subjectnum;//�����
	double grade;//����
};

struct system input_is_I(int cnt) {//I�϶�
	struct system tmp;//�ӽ� ����ü����
	int i;
	char subname[31];
	double sum = 0, subgrade;

	scanf("%s %s %d", tmp.name, tmp.studentid, &tmp.subjectnum);//�̸�,�й�,����� �Է¹ޱ�
	for (i = 0; i < tmp.subjectnum; i++) {//�������ŭ �����̸��� ������ �Է¹ޱ�
		scanf("%s %lf", subname, &subgrade);
		sum += subgrade;//sum�� ���صα�
	}
	tmp.grade = sum / (double)tmp.subjectnum;//�׷��� ���� ��������� grade�� �����صα�

	return tmp;//����ü ����
}

void input_is_S(struct system *pst, int cnt) {//S�϶�
	struct system forsort[100], tmp, *p, *q;//���Ŀ� ����� �ӽ� ����ü �迭 ����
	for (p = &forsort, q = pst; p < forsort + cnt; p++, q++) {
		*p = *q;//�ӽ� ����ü�� ���� ����ü ����
	}
	for (p = &forsort; p < forsort + cnt; p++) {//�̸��� ����
		for (q = p + 1; q < forsort + cnt; q++) {
			if (strcmp(p->name, q->name) > 0) {
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
	for (p = &forsort; p < forsort + cnt; p++) {//���ĵ� �ӽñ���ü ���
		printf("%s %s %d %.2lf\n", p->name, p->studentid, p->subjectnum, p->grade);
	}
}

int input_is_D(struct system *pst, int cnt, char Dname[]) {//D�϶�
	struct system *p, *q;
	for (p = pst; p < pst + cnt; p++) {
		if (strcmp(p->name, Dname) == 0) {//����ü�� �Է¹��� �̸��� ���� �̸��� �ִٸ�
			for (q = p; q < pst + cnt; q++) {//�� ����ü�� ���������� ��ĭ�� ��ܿ���
				*q = *(q + 1);
			}
			return 1;//��ĭ�� ��� �Դٸ� cnt--�� �ؾ��ϴ� �� �Լ��� flagó�� ����Ͽ� 1�� ����
		}
	}
	return 0;
}

void input_is_P(struct system *pst, int cnt) {//P�϶�
	struct system *p;
	for (p = pst; p < pst + cnt; p++) {//�Է¹��� ������� ���
		printf("%s %s %d %.2lf\n", p->name, p->studentid, p->subjectnum, p->grade);//������ �Ҽ��� ��°�ڸ�����
	}
}

int main() {
	struct system l[100], *pst = &l;//�л��� �ִ� 100��
	char input[40], Dname[31];
	int cnt = 0;//cnt�� ����ü�� �ִ� �л���

	do {
		gets(input);//�Է¹ޱ�

		if (input[0] == 'I') {//I�϶�
			*(pst + cnt) = input_is_I(cnt);//�̸� �й� ����� ����� �Է¹޴� �ڵ�
			cnt++;//�л����� �ϳ� �þ����� cnt++
		}
		else if (input[0] == 'S') {//S�϶�
			input_is_S(pst, cnt);
		}
		else if (input[0] == 'D') {//D�϶�
			strcpy(Dname, input + 2);//input[0]='D'�̰� �����̽��� �ڿ� �̸��� �ִٸ� Dname�� �޾Ƶα�
			if (strcmp(Dname, "\0") != 0) {//�̸��� �ִٸ� input_is_D�Լ� ����
				if (input_is_D(pst, cnt, Dname) == 1) {//�Ѹ� �����ٸ� cnt--
					cnt--;
				}
			}
		}
		else if (input[0] == 'P') {//P�϶�
			input_is_P(pst, cnt);
		}
		else if (input[0] == 'Q') break; //Q�϶�, ��������
	} while (1);
}