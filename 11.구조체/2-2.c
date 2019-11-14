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
	int i, j, n, m, cnt = 0, flag;
	int stdy, stdm, stdd;//������ �Ǵ� ��¥(���ó�¥) �Է¹ޱ�
	int tmpy, tmpm;//�ӽ��� y�� m����
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//����ϰ�� ��
	int leapmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//�����ϰ�� ��
	int inputid[50];

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

	scanf("%d", &m);//��ü ��� ������ �䱸�� �л��� ��
	for (i = 0; i < m; i++) {//��ü ��� ������ �䱸�� �л��� �й��� inputid�� �Է¹ޱ�
		scanf("%d", &inputid[i]);
	}

	for (i = 0; i < m; i++) {
		flag = 0;//�ʱ�ȭ
		printf("%d", inputid[i]);//�ϴ� inputid�� �ִ� �й� ���
		for (j = 0; j < n; j++) {
			if (inputid[i] == l[j].studentid &&l[j].gapdate > 15) {//��ü�� �ִ� �л���
				flag++;//��ü�� ���ٸ� flag�� 0�̴�
				printf(" %d(%d)", l[j].bookid, (l[j].gapdate - 15) * 100);//å�� �Ϸù�ȣ, ��ü�� ���
			}
		}
		if (flag == 0) printf(" X");//��ü�� ���� �л��� �й��� X�� ���
		printf("\n");
	}
}