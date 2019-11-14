#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

void compareString(char a[], char b[]) {//두 문자열이 같은지 확인 하는 함수
	if (strcmp(a, b) == 0) {//같은 경우 
		printf("identical");
	}
	else printf("different");//다른 경우
}

int main() {
	char tmp[51];//임시로 문자열을 입력받을 tmp
	char *str1, *str2;//2개의 포인터

	gets(tmp);//입력받고
	str1 = (char *)malloc((strlen(tmp) + 1) * sizeof(char));//동적할당을 하고
	strcpy(str1, tmp);//다시 넣기

	gets(tmp);//입력받고
	str2 = (char *)malloc((strlen(tmp) + 1) * sizeof(char));//동적할당을 하고
	strcpy(str2, tmp);//다시 넣기

	compareString(str1, str2);//비교하기
	free(str1);//할당한 메모리 해제
	free(str2);
}