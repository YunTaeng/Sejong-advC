#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct customer {//����ü ����
	char id[5];
	char *name;
	char *phone;
	struct customer *next;
}CUS;


int main() {
	CUS *st, *p;
	int i, j, n, cnt;
	char tmp1[50], tmp2[20], targetnum;

	scanf("%d", &n);//n�Է¹ޱ�

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

	for (i = 0; i < n; i++) {
		st[i].next = NULL;//�ʱ�ȭ
		for (j = i + 1; j < n; j++) {
			if (st[i].id[3] == st[j].id[3]) {//������ ��ȣ�� ���ٸ�
				st[i].next = &st[j];  //���� ����ü�� �ּҸ� ����ü �����ͷ� ����
				break; // �����͸� ���� �Ǿ�� �ϹǷ� break
			}
		}
	}

	scanf("%c", &targetnum);//ã�� ���� �Է¹ޱ�

	for (p = st; p < st + n; p++) {
		if (p->id[3] == targetnum) break;//p�� �����س��� ����ü�� ���� ��ġ�� �ְ� ��
	}

	cnt = 1;
	for (; p; p = p->next) {
		printf("%s %s %d\n", p->name, p->phone, cnt++);//�����س��� ����ü ���
	}


}

