#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

struct parking {//�Է¹޴� ���� ����
	int carnum;//����ȣ
	int studentid;//�й�
	char inouttime[40];//���� �ð��� ������ �ð��� �� ��������  �ǹ̾����� �׳� �ѹ��� �ޱ�
};

int main() {
	int i, j, k, n, cnt = 0, flag;
	struct parking l[100], tmp;//���Ŀ� ����� tmp����ü����
	int list[100];

	scanf("%d", &n);//n�Է¹ޱ�

	for (i = 0; i < n; i++) {
		scanf("%d %d", &l[i].carnum, &l[i].studentid);//����ȣ,�й��Է¹ޱ�
		gets(l[i].inouttime);//�����Խð� �޾Ƶα�
	}

	for (i = 0; i < n; i++) {//�й��� ����
		for (j = i + 1; j < n; j++) {
			if (l[i].studentid > l[j].studentid) {
				tmp = l[i];
				l[i] = l[j];
				l[j] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (l[i].studentid == l[j].studentid && l[i].carnum != l[j].carnum) {//�й��� ���� ����ȣ�� �ٸ���쿡(�����̿��ڶ��)
				flag = 0;
				for (k = 0; k < cnt; k++) {
					if (list[k] == l[i].studentid) flag++;//list�� �̹� �ִ� �й��� �ƴ϶�� flag=0
				}
				if (flag == 0) {
					list[cnt++] = l[i].studentid;//list�� �־�α�
				}
			}
		}
	}

	for (k = 0; k < cnt; k++) {//list ���
		printf("%d\n", list[k]);
	}
}