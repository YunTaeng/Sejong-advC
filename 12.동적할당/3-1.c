#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct student {
	char *studentName; // 학생 이름
	char id[5]; // 학생 학번
	char *subjectName; // 과목 이름
	double subjectScore; // 과목 점수
}STUDENT;

int main() {
	int n, k;
	char tmp1[101], tmp2[101];
	STUDENT *st, *p, *q, tmpst;
	scanf("%d", &n);

	st = (STUDENT *)malloc(n * sizeof(STUDENT));//입력받은 n에 따라 구조체 동적할당

	for (p = st; p < st + n; p++) {
		scanf("%s %s %s %lf", tmp1, p->id, tmp2, &p->subjectScore);//학생정보 입력받기
		p->studentName = (char*)malloc((strlen(tmp1) + 1) * sizeof(char));//학생이름 동적할당
		strcpy(p->studentName, tmp1);//동적할당 받은거에 넣기
		p->subjectName = (char*)malloc((strlen(tmp2) + 1) * sizeof(char));//과목이름 동적할당
		strcpy(p->subjectName, tmp2);//동적할당 받은거에 넣기
	}

	scanf("%d", &k);

	for (p = st + n; p >= st; p--) {
		for (q = st; q < p - 1; q++) {
			if (q->subjectScore < (q + 1)->subjectScore) {
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
		}
	}

	p = st + k - 1;
	printf("%s %s %s %.2lf", p->studentName, p->id, p->subjectName, p->subjectScore);

	for (p = st; p < st + n; p++) {//할당한 메모리 해제
		free(p->studentName);
		free(p->subjectName);
	}
	free(st);//할당한 메모리 해제
}