#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct subject {
	char *name; // 과목 이름
	double score; // 과목 점수
}SUB;

typedef struct student {
	char *name; // 학생 이름
	char id[5]; // 학생 학번
	int numSubject; // 과목 개수
	struct subject *psub; // 과목 구조체 포인터
	double avg; // 모든 과목의 평균 점수
}STUDENT;

void input_data(STUDENT *L) {//학생의 정보를 입력받는 함수
	int i, cnt = 0, len, tmpid;
	char input[101], *p, tmpsc, **word;
	double avg = 0;

	gets(input);

	len = strlen(input);//길이 len에 받아두기
	for (i = 0; i < len; i++) {
		if (input[i] == ' ') {//스페이스바의 갯수에 따라 과목수가 정해진다.
			cnt++;
		}
	}
	L->numSubject = cnt / 2;//과목수는 스페이스바의 갯수의 2를 나눈것의 내림과 같다
	word = (char **)malloc(sizeof(char *) * (cnt + 1));//word라는 문자형 포인트배열
	cnt = 0;
	word[cnt++] = input;//시작위치
	for (i = 0; i < len; i++) {//스페이스바를 기준으로 단어를 끊는 코드
		if (input[i] == ' ') {//스페이스바가 나올 때 마다 끊기
			input[i] = '\0';
			word[cnt++] = &input[i + 1];//스페이스바 다음이 다음 단어의 시작이므로
		}
	}

	L->name = (char *)malloc(sizeof(char) * (strlen(word[0]) + 1));//맨처음 단어는 이름이니 메모리를 동적할당해준뒤 카피하기
	strcpy(L->name, word[0]);
	strcpy(L->id, word[1]);//두번째 단어는 학번이다

	L->psub = (SUB *)malloc(sizeof(SUB) * L->numSubject);//과목수에 따라 구조체 SUB 동적할당

	for (i = 0; i < L->numSubject; i++) {
		L->psub[i].name = (char *)malloc(sizeof(char) * (strlen(word[2 * i + 2]) + 1));//과목이름 동적할당후 넣기
		strcpy(L->psub[i].name, word[2 * i + 2]);
		tmpsc = atoi(word[2 * i + 3]);
		L->psub[i].score = (double)tmpsc;//성적은 atoi후 double로 명시적형변환으로 넣기
	}

	for (i = 0; i < L->numSubject; i++) {
		avg += L->psub[i].score;//성적을 다 더하기
	}
	L->avg = avg / L->numSubject;//평균은 성적/과목수
}


int main() {
	int n, k, i;
	STUDENT *st, *p, *q, tmpst;
	SUB *sp, *max;

	scanf("%d", &n);//n입력받기
	getchar();

	st = (STUDENT *)malloc(n * sizeof(STUDENT));//입력받은 n에 따라 구조체 동적할당

	for (i = 0; i < n; i++) {
		input_data(&st[i]);
	}

	for (p = st + n; p >= st; p--) {//정렬하기
		for (q = st; q < p - 1; q++) {
			if (q->avg < (q + 1)->avg) {//성적평균이 높은 학생부터 내림차순 정렬  
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
			else if (q->avg == (q + 1)->avg && strcmp(q->id, (q + 1)->id) > 0) {//평균 점수가 같은 학생의 경우에는 학번 순으로 정렬
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}

		}
	}

	scanf("%d", &k);//k입력받기
	p = st + k - 1;

	max = p->psub;//max 초기화
	for (sp = p->psub; sp < p->psub + p->numSubject; sp++) {
		if (sp->score > max->score) {
			max = sp;
		}
	}


	printf("%s %s %.2lf %s %.2lf", p->name, p->id, p->avg, max->name, max->score);

	for (p = st; p < st + n; p++) {//할당한 메모리 해제
		for (sp = p->psub; sp < p->psub + p->numSubject; sp++) {
			free(sp->name);
		}
		free(p->psub);
		free(p->name);
	}
	free(st);//할당한 메모리 해제
}