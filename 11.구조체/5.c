#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
//포인터로풀기
struct system {//학생들의 정보를 저장할 구조체 선언
	char name[31];//이름
	char studentid[9];//학번
	int subjectnum;//과목수
	double grade;//성적
};

struct system input_is_I(int cnt) {//I일때
	struct system tmp;//임시 구조체선언
	int i;
	char subname[31];
	double sum = 0, subgrade;

	scanf("%s %s %d", tmp.name, tmp.studentid, &tmp.subjectnum);//이름,학번,과목수 입력받기
	for (i = 0; i < tmp.subjectnum; i++) {//과목수만큼 과목이름과 과목성적 입력받기
		scanf("%s %lf", subname, &subgrade);
		sum += subgrade;//sum에 더해두기
	}
	tmp.grade = sum / (double)tmp.subjectnum;//그렇게 구한 점수평균은 grade에 저장해두기

	return tmp;//구조체 리턴
}

void input_is_S(struct system *pst, int cnt) {//S일때
	struct system forsort[100], tmp, *p, *q;//정렬에 사용할 임시 구조체 배열 선언
	for (p = &forsort, q = pst; p < forsort + cnt; p++, q++) {
		*p = *q;//임시 구조체에 본래 구조체 복사
	}
	for (p = &forsort; p < forsort + cnt; p++) {//이름순 정렬
		for (q = p + 1; q < forsort + cnt; q++) {
			if (strcmp(p->name, q->name) > 0) {
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
	for (p = &forsort; p < forsort + cnt; p++) {//정렬된 임시구조체 출력
		printf("%s %s %d %.2lf\n", p->name, p->studentid, p->subjectnum, p->grade);
	}
}

int input_is_D(struct system *pst, int cnt, char Dname[]) {//D일때
	struct system *p, *q;
	for (p = pst; p < pst + cnt; p++) {
		if (strcmp(p->name, Dname) == 0) {//구조체에 입력받은 이름과 같은 이름이 있다면
			for (q = p; q < pst + cnt; q++) {//그 구조체는 날려버리고 한칸씩 당겨오기
				*q = *(q + 1);
			}
			return 1;//한칸씩 당겨 왔다면 cnt--를 해야하니 이 함수를 flag처럼 사용하여 1을 리턴
		}
	}
	return 0;
}

void input_is_P(struct system *pst, int cnt) {//P일때
	struct system *p;
	for (p = pst; p < pst + cnt; p++) {//입력받은 순서대로 출력
		printf("%s %s %d %.2lf\n", p->name, p->studentid, p->subjectnum, p->grade);//성적은 소수점 둘째자리까지
	}
}

int main() {
	struct system l[100], *pst = &l;//학생은 최대 100명
	char input[40], Dname[31];
	int cnt = 0;//cnt는 구조체에 있는 학생수

	do {
		gets(input);//입력받기

		if (input[0] == 'I') {//I일때
			*(pst + cnt) = input_is_I(cnt);//이름 학번 과목수 과목등 입력받는 코드
			cnt++;//학생수가 하나 늘었으니 cnt++
		}
		else if (input[0] == 'S') {//S일때
			input_is_S(pst, cnt);
		}
		else if (input[0] == 'D') {//D일때
			strcpy(Dname, input + 2);//input[0]='D'이고 스페이스바 뒤에 이름이 있다면 Dname에 받아두기
			if (strcmp(Dname, "\0") != 0) {//이름이 있다면 input_is_D함수 실행
				if (input_is_D(pst, cnt, Dname) == 1) {//한명 지웠다면 cnt--
					cnt--;
				}
			}
		}
		else if (input[0] == 'P') {//P일때
			input_is_P(pst, cnt);
		}
		else if (input[0] == 'Q') break; //Q일때, 종료조건
	} while (1);
}