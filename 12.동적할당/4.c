#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct tourcity {//������ ����ü ����
	char sights[21];
	int pay;
	char inout;
	char startday[9];
	char cityname[21];
}TOURCITY;

int main() {
	TOURCITY **st, maxst;
	int n, i, j, *sightnum;
	char **citynames, tmp[101];

	scanf("%d", &n);//n�Է¹ޱ�
	getchar();

	citynames = (char **)malloc(sizeof(char *) * n);//�Է¹���n�� ���� ���� �̸� �����Ҵ�
	if (citynames == NULL) {//�޸� �����Ҵ��� �����ϴ� ��� Not Enough Memory.�� ����ϰ� ����
		printf("Not Enough Memory.");
		return -1;
	}
	sightnum = (int *)malloc(sizeof(int) * n);//�Է¹���n�� ���� ������ ������ �� �迭 �����Ҵ�
	if (sightnum == NULL) {
		printf("Not Enough Memory.");
		return -1;
	}
	st = (TOURCITY **)malloc(sizeof(TOURCITY *) * n);//����ü �迭 �����Ҵ�
	if (st == NULL) {
		printf("Not Enough Memory.");
		return -1;
	}

	for (i = 0; i < n; i++) {
		scanf("%s", tmp);//������ ���ڿ� �Է¹ޱ�
		citynames[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));//�� ���̸�ŭ �����Ҵ�
		if (citynames[i] == NULL) {
			printf("Not Enough Memory.");
			return -1;
		}
		strcpy(citynames[i], tmp);//�����Ҵ�� �޸𸮿� tmp�ֱ�
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &sightnum[i]);//�Է¹���n�� ���� ������ ������ �� �Է¹ޱ�
	}

	for (i = 0; i < n; i++) {
		st[i] = (TOURCITY *)malloc(sizeof(TOURCITY)* sightnum[i]); //������ ������ �Է¹޾� �����Ҵ�
		if (st[i] == NULL) {
			printf("Not Enough Memory");
			return -1;
		}
		for (j = 0; j < sightnum[i]; j++) {//�����Ҵ�� ����ü�� �Է¹ޱ�
			scanf("%s %d %c %s", st[i][j].sights, &st[i][j].pay, &st[i][j].inout, st[i][j].startday);
			strcpy(st[i][j].cityname, citynames[i]);//����ü�� �����̸��� �Է��ϱ�
		}
	}

	maxst = st[0][0];
	for (i = 0; i < n; i++) {//�������� ����ᰡ ���� ��� �������� ã�� �ڵ�
		for (j = 0; j < sightnum[i]; j++) {//����ᰡ �ٸ���
			if (maxst.pay < st[i][j].pay) {
				maxst = st[i][j];
			}
			else if (maxst.pay == st[i][j].pay) {//����ᰡ ���� ��
				if (strcmp(maxst.startday, st[i][j].startday) > 0) {//������ �������� ���� ������ ����
					maxst = st[i][j];
				}
			}
		}
	}

	printf("%s %s %d %s %c", maxst.cityname, maxst.sights, maxst.pay, maxst.startday, maxst.inout);//�������� ����ᰡ ���� ��� �������� ���� ���

	for (i = 0; i < n; i++) {//�޸� ����
		free(citynames[i]);
		free(st[i]);
	}
	free(sightnum);
	free(citynames);
	free(st);
}