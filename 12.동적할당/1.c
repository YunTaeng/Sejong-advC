#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

void compareString(char a[], char b[]) {//�� ���ڿ��� ������ Ȯ�� �ϴ� �Լ�
	if (strcmp(a, b) == 0) {//���� ��� 
		printf("identical");
	}
	else printf("different");//�ٸ� ���
}

int main() {
	char tmp[51];//�ӽ÷� ���ڿ��� �Է¹��� tmp
	char *str1, *str2;//2���� ������

	gets(tmp);//�Է¹ް�
	str1 = (char *)malloc((strlen(tmp) + 1) * sizeof(char));//�����Ҵ��� �ϰ�
	strcpy(str1, tmp);//�ٽ� �ֱ�

	gets(tmp);//�Է¹ް�
	str2 = (char *)malloc((strlen(tmp) + 1) * sizeof(char));//�����Ҵ��� �ϰ�
	strcpy(str2, tmp);//�ٽ� �ֱ�

	compareString(str1, str2);//���ϱ�
	free(str1);//�Ҵ��� �޸� ����
	free(str2);
}