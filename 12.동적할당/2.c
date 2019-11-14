#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct st {
	char *str; // 문자열 저장
	int cnt; // 자음 수 저장
}ST;

int main() {
	ST *l, *p, *q, tmpst;
	int n, i, len, cnt;
	char tmp[101];

	scanf("%d", &n);

	l = (ST *)malloc(n * sizeof(ST));//입력받은 n에 따라 동적할당

	for (p = l; p < l + n; p++) {
		scanf("%s", tmp);//임시로 입력받기
		p->str = (char*)malloc((strlen(tmp) + 1) * sizeof(char));//책 이름 str 동적할당
		strcpy(p->str, tmp);//동적할당 받은거에 넣기
	}

	for (p = l; p < l + n; p++) {
		len = strlen(p->str);//책이름의 길이
		cnt = 0;//초기화
		for (i = 0; i < len; i++) {//모음이 아니라면
			if (p->str[i] != 'A' && p->str[i] != 'a' && p->str[i] != 'E' && p->str[i] != 'e' && p->str[i] != 'I' && p->str[i] != 'i' && p->str[i] != 'O' && p->str[i] != 'o' && p->str[i] != 'U' && p->str[i] != 'u') {
				cnt++;//cnt증가
			}
		}
		p->cnt = cnt;//총 자음수 구조체의 cnt에 넣기
	}

	for (p = l + n; p >= l; p--) {//자음의 수가 가장 많은 문자열부터 내림차순으로 정렬, 자음 수가 같으면 입력된 순서대로 정렬
		for (q = l; q < p - 1; q++) {
			if (q->cnt < (q + 1)->cnt) {//tmpst를 이용하여 바꿔줌
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
		}
	}

	for (p = l; p < l + n; p++) {
		printf("%s\n", p->str);//출력
	}

	for (p = l; p < l + n; p++) {//할당한 메모리 해제
		free(p->str);
	}
	free(l);//할당한 메모리 해제
}