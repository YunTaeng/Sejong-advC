#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[1001], *word[100], *p; //�ִ���� 1000�� ���ڿ�
	int wordlen[100], i, j, k, cnt = 0;

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

	for (i = 0; i < cnt; i++) {//��ó������ cnt(=�ܾ��� �Ѱ���,N )����
		for (j = i + 1; j < cnt; j++) {//i��° ������ �͵��� ��
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

	printf("%s", word[k - 1]);//K��° ��ġ�� �ܾ ���
}