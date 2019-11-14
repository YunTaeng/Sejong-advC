#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

struct list {//����ü list ����
	int studentid;
	int bookid;
	int y;
	int m;
	int d;//������� �Է¹޴� ����
	int gapdate;//��¥�� �󸶳� ��������
};

int leapyearcheck(int y) //�����̸� 1, ����̸� 0 ����
{
	int flag = 0;

	if (y % 4 == 0)
	{
		flag = 1;
		if (y % 100 == 0)
		{
			flag = 0;
			if (y % 400 == 0)
				flag = 1;
		}
	}
	return flag;//flag ����
}

int main() {
	struct list l[50];
	int i, j, n, cnt = 0, flag;
	int stdy, stdm, stdd;//������ �Ǵ� ��¥(���ó�¥) �Է¹ޱ�
	int tmpy, tmpm;//�ӽ��� y�� m����
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//����ϰ�� ��
	int leapmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//�����ϰ�� ��
	int msg[50];//�޼����� ���� ����� ����Ʈ

	scanf("%d %d-%d-%d", &n, &stdy, &stdm, &stdd);//������ �Է¹ޱ�

	for (i = 0; i < n; i++) {
		scanf("%d %d %d-%d-%d", &l[i].studentid, &l[i].bookid, &l[i].y, &l[i].m, &l[i].d); //n��ŭ �Է¹ޱ�
	}

	for (i = 0; i < n; i++) {//�Է¹��� ���� ��,�� �κ��� ���س�,������ tmpy,tmpm�� ���ذ��� d�� ���Ѱ� ����ΰ� y��m�� ���ؼ� ���ϱ�
		l[i].gapdate = 0;//�ʱ�ȭ
		for (tmpy = l[i].y, tmpm = l[i].m; tmpy <= stdy && tmpm < stdm; tmpm++) {
			if (leapyearcheck(tmpy) == 1) {//�����ϰ��
				l[i].gapdate += leapmonth[tmpm - 1];
			}
			else {//����ϰ��
				l[i].gapdate += month[tmpm - 1];
			}

		}
		l[i].gapdate += (stdd - l[i].d);//d�� ���Ͽ� ���
	}


	for (i = 0; i < n; i++) {
		if (l[i].gapdate > 15) {//15���� ��������� ��ü
			flag = 0;
			for (j = 0; j < cnt; j++) {//msg�迭�� �̹� �ִ��� 
				if (l[i].studentid == msg[j]) flag++;
			}
			if (flag == 0) msg[cnt++] = l[i].studentid;//flag�� 0�϶� �߰�
		}
	}

	for (i = 0; i < cnt; i++) {//msg����Ʈ ���
		printf("%d\n", msg[i]);
	}
}