#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[1001], *word[100], *p, *q; //�ִ���� 1000�� ���ڿ�
	int wordcnt, i, j, k, cnt = 0, similar;
	char a[101], b[101];

	gets(str);//������ �����ϴ� ���ڿ� �Է¹ޱ�
	scanf("%d", &k);

	word[cnt] = str;//word�������� ó���� �迭str�� �Ǿ�
	cnt++;

	for (i = 0; str[i] != '\0'; i++) {//�����̽��ٰ� ������ ���� word�����Ϳ� str[i+1]�� �ּҸ� �Է�
		if (str[i] == ' ') {
			str[i] = '\0';
			word[cnt++] = &str[i + 1];//�����̽��� ������ ���� �ܾ��� �����̹Ƿ�
		}
	}
	wordcnt = cnt;//�ܾ��� ���� �޾Ƴ���

	for (i = 0; i < wordcnt; i++) {//��ó������ �ܾ��� �Ѱ�������
		for (j = i + 1; j < wordcnt; j++) {//i�� ������ �͵��� ��
			if (strlen(word[i]) < strlen(word[j])) { //���̰� �ٸ� ��� ���̰� �� ���� ������
				p = word[i];
				word[i] = word[j];
				word[j] = p;
			}
			else if (strlen(word[i]) == strlen(word[j]) && (strcmp(word[i], word[j]) > 0)) {//���̰� ������� ���� ������
				p = word[i];
				word[i] = word[j];
				word[j] = p;
			}
		}
	}
	printf("%s\n", word[k - 1]);//K��° ��ġ�� �ܾ ���

	//���� ������ word[k-1]�� �ȴ�

	for (i = 0; i < wordcnt; i++) {
		if (i == k - 1) continue;//�����Ͱ��� ������ �ʰ�

		strcpy(a, word[k - 1]);//a���� ������ word[k-1]�� ����
		strcpy(b, word[i]);//b���� �񱳴���� word[i]�� ����

		cnt = 0;//cnt�ʱ�ȭ

		for (p = a; *p; p++) { //�迭�� ���� �������� �ֳ� ã��
			for (q = b; *q; q++) {
				if (*p == *q) {//������� cnt++�� ��. 
					cnt++;
					*q = ' ';// �ѹ� �������Ƿ� *q�� �������� �ٲ�.*q ���� ���� ���ڰ� �������� �ٲ����ʰ� break
					break;
				}
			}
		}
		if (strlen(word[k - 1]) > strlen(word[i])) similar = strlen(word[k - 1]) - cnt;//�� ���ڿ��� ��Ϳ��� cnt�� �� ���� similar�̶���
		else similar = strlen(word[i]) - cnt;//similar�� -1�̳� 1�̸� word[k-1]���� �Ѱ��� ���ڸ� �߰��ϰų� ���� ������ִٴ¶�

		if (-1 <= similar && similar <= 1) printf("%s\n", word[i]);//�񱳴���� ���ǿ� �����ϸ� ���
	}
}