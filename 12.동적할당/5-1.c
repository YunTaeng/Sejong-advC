#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct customer {//����ü ����
	char id[5];
	char *name;
	char *phone;
}CUS;


int main() {
	CUS *st;
	int i, j, n;
	char tmp1[50], tmp2[20], targetid[5];

	scanf("%d", &n);

	st = (CUS *)malloc(n * sizeof(CUS));//�Է¹��� n��ŭ ����ü �����Ҵ�

	for (i = 0; i < n; i++) {
		scanf("%s %s", tmp1, tmp2);//�Է¹ޱ�
		getchar();
		st[i].name = (char *)malloc(sizeof(char)*(strlen(tmp1) + 1));//�Է¹��� ���� �����Ҵ� �� �Է�
		strcpy(st[i].name, tmp1);

		st[i].phone = (char *)malloc(sizeof(char)*(strlen(tmp2) + 1));//�Է¹��� ���� �����Ҵ� �� �Է�
		strcpy(st[i].phone, tmp2);

		strcpy(st[i].id, tmp2 + 9);//��ȭ��ȣ ���ڸ� 4�ڸ� id�� ����
	}
	scanf("%s", targetid);

	for (i = 0; i < n; i++) {//Ÿ��id�� ������ �� ����ü�� ���� ���
		if (strcmp(st[i].id, targetid) == 0) {
			printf("%s %s %d", st[i].name, st[i].phone, i + 1);
		}
	}
}

