#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

struct parking {
	int carnum;
	int studentid;
	char inouttime[40];//������� �⺻������ �Է¹޴�����
	int timepass;//�̿�ð�
	int penalty;//�����̿�������
	int pay;//�������
};


int main() {
	int i, j, k, n, m, intime, outtime, cnt = 0, flag, inputcarnum[100];
	struct parking l[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &l[i].carnum, &l[i].studentid);//����ȣ,�й��Է¹ޱ�
		gets(l[i].inouttime);//�����Խð� �޾Ƶα�
	}

	for (i = 0; i < n; i++) {//inouttime�� ����:�������� :�� ���Ͽ� intime�� outtime�� ���ϱ�
		intime = 0;//�ʱ�ȭ
		outtime = 0;
		for (j = 0;; j++) {
			if (l[i].inouttime[j] == ':') {//�� �ð� :�� ���Ͽ� intime�� �޾Ƶα�
				k = j - 2;
				while (k != j + 2) {//���� ���ڸ��� ���ϰ� 60�� ���ϰ� ���� ���ڸ� ���ϱ�
					if (k == j) intime *= 60;//�ð��� 60���ϱ�
					else if (k == j - 2 || k == j + 1) {
						intime += (l[i].inouttime[k] - '0') * 10 + l[i].inouttime[k + 1] - '0';
					}
					k++;
				}
				j++;//j�� :�� �ִ�ä�� �극��ũ �ϸ� �ȵǹǷ� j++
				break;
			}

		}
		for (;; j++) {
			if (l[i].inouttime[j] == ':') {//���� �ð� :�� ���Ͽ� intime�� �޾Ƶα�
				k = j - 2;
				while (k != j + 2) {
					if (k == j) outtime *= 60;//���� ���ڸ��� ���ϰ� 60�� ���ϰ� ���� ���ڸ� ���ϱ�
					else if (k == j - 2 || k == j + 1) {//�ð��� 60���ϱ�
						outtime += (l[i].inouttime[k] - '0') * 10 + l[i].inouttime[k + 1] - '0';
					}
					k++;
				}
				break;//�ð��� �� �޾Ƶ����� �극��ũ�� ������
			}

		}
		l[i].timepass = outtime - intime;//�̿�ð� timepass�� �޾Ƶα�
	}

	for (i = 0; i < n; i++) {
		flag = 0;//�ʱ�ȭ
		for (j = 0; j < i; j++) {//�й��� ���� ����ȣ�� �ٸ����(�����̿���)�� üũ
			if (l[i].studentid == l[j].studentid && l[i].carnum != l[j].carnum) {
				flag++;
			}
		}
		if (flag != 0) {//�����̿��ڶ�� 
			for (j = 0; j < n; j++) {
				if (l[i].studentid == l[j].studentid) {
					l[j].penalty = 1;//penalty�� 1�� ǥ��
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (l[i].penalty == 1) l[i].pay = 100000;//�����̿��ڴ� ����100000��
		else {
			if (l[i].timepass <= 60) l[i].pay = 3000;//���� 1�ð��� 3000��
			else if (l[i].timepass <= 330) {//��������� 30000���� ���� �ʴ°��
				l[i].pay = 3000;
				l[i].timepass -= 60;
				while (l[i].timepass > 0) {//�⺻�� 1�ð� 3000���� 10�и��� 1000���� �߰�
					l[i].timepass -= 10;
					l[i].pay += 1000;
				}
			}
			else l[i].pay = 30000;//�̿�ð��� 330�� �̻��̶�� �ִ� ��������� 30000���� �����Ƿ�
		}
	}

	scanf("%d", &m);//��� ���� �� ������ ��� �������

	for (i = 0; i < m; i++) {
		scanf("%d", &inputcarnum[i]);//��� ���� �� ������ ����Է¹ޱ�
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (inputcarnum[i] == l[j].carnum) printf("%d\n", l[j].pay);//�Է¹��� ����ȣ�� l���� ����ȣ�� ������ ���� ����ü�� pay���
		}
	}
}