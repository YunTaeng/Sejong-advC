#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

typedef struct student {//����ü student
	char name[10];
	char studentid[11];
	char lastgrade;
}STUDENT;//typedef�� ����� ������

int main() {
	int i, j;
	STUDENT l[5];//5���Է¹���
	char targetname[10];
	int targetidyear = 0, tmpidyear, flag = 0, targetnum;

	for (i = 0; i < 5; i++) {
		scanf("%s %s %c", l[i].name, l[i].studentid, &l[i].lastgrade);//5�� �л��� �̸��� �� �л��� �й� �� �����б� ��������� �Է¹ޱ�
	}
	scanf("%s", targetname);//ó���� �Է¹޴� �̸� �����صα�

	for (i = 0; i < 5; i++) {
		if (strcmp(targetname, l[i].name) == 0) {//�Է¹��� �̸��� ����ü�� �̸��� �������
			targetnum = i;//�迭�� ���°���� �޾Ƶα�
			for (j = 0; j < 4; j++) {//���г⵵�� targeidyear�� �޾Ƶα�
				targetidyear *= 10;
				targetidyear += l[i].studentid[j] - '0';
			}
		}
	}
	for (i = 0; i < 5; i++) {
		if (i == targetnum) continue;//i�� targetnum�̶�� ��������� ���ϴ� ���̴� continue���ش�
		tmpidyear = 0;
		for (j = 0; j < 4; j++) {//i�� �ٲ㰡�� ���г⵵ �޾Ƶα�
			tmpidyear *= 10;
			tmpidyear += l[i].studentid[j] - '0';
		}
		if (targetidyear == tmpidyear && l[targetnum].lastgrade == l[i].lastgrade) {//���г⵵���� ������ ������ ���
			printf(" %s\n", l[i].name);
			flag = 1;//������ �´��л��� �ϳ��� �ִٸ� flag=1
		}
	}
	if (flag == 0) printf("0");//flag�� 0�̶�� ���ǿ� �´� �л��� ���ٴ� ���̹Ƿ� 0�� ���
}