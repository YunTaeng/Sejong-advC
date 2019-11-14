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
	CUS *st, *p, *q;
	int i, j, n, cnt;
	char tmp1[50], tmp2[20], targetid[5];

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

	for (i = 0; i < n; i++) {//����ü�� �����ϴ� �ڵ�
		st[i].next = NULL;//�ʱ�ȭ
		for (j = i + 1; j < n; j++) {
			if (st[i].id[3] == st[j].id[3]) {//id�� ������ ��ȣ�� ���ٸ�
				st[i].next = &st[j];  //���� ����ü�� �ּҸ� ����ü �����ͷ� ����
				break; // �����͸� ���� �Ǿ�� �ϹǷ� break
			}
		}
	}

	scanf("%s", targetid);//ã�� ���� �Է¹ޱ�

	for (p = st; p < st + n; p++) {
		cnt = 1;
		if (p->id[3] == targetid[3]) {//����ü ������� ������ �Ǵ� idã��
			for (q = p; q; q = q->next) {//������� ���� cnt�� �÷����� ã��
				if (strcmp(q->id, targetid) == 0) {//ã���� ����ϰ� ����
					printf("%s %s %d\n", q->name, q->phone, cnt);
					return 0;
				}
				cnt++;
			}
		}
	}


	for (i = 0; i < n; i++) {//�޸� �Ҵ� ����
		free(st[i].name);
		free(st[i].phone);
	}
	free(st);
}

