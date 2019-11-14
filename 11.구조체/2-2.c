#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

struct list {//구조체 list 선언
	int studentid;
	int bookid;
	int y;
	int m;
	int d;//여기까지 입력받는 정보
	int gapdate;//날짜가 얼마나 지났는지
};

int leapyearcheck(int y) //윤년이면 1, 평년이면 0 리턴
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
	return flag;//flag 리턴
}

int main() {
	struct list l[50];
	int i, j, n, m, cnt = 0, flag;
	int stdy, stdm, stdd;//기준이 되는 날짜(오늘날짜) 입력받기
	int tmpy, tmpm;//임시의 y와 m선언
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//평년일경우 월
	int leapmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//윤년일경우 월
	int inputid[50];

	scanf("%d %d-%d-%d", &n, &stdy, &stdm, &stdd);//기준일 입력받기

	for (i = 0; i < n; i++) {
		scanf("%d %d %d-%d-%d", &l[i].studentid, &l[i].bookid, &l[i].y, &l[i].m, &l[i].d); //n만큼 입력받기
	}

	for (i = 0; i < n; i++) {//입력받은 것의 년,월 로부터 기준년,월까지 tmpy,tmpm를 더해가며 d에 대한건 내비두고 y와m에 대해서 더하기
		l[i].gapdate = 0;//초기화
		for (tmpy = l[i].y, tmpm = l[i].m; tmpy <= stdy && tmpm < stdm; tmpm++) {
			if (leapyearcheck(tmpy) == 1) {//윤년일경우
				l[i].gapdate += leapmonth[tmpm - 1];
			}
			else {//평년일경우
				l[i].gapdate += month[tmpm - 1];
			}
		}
		l[i].gapdate += (stdd - l[i].d);//d에 대하여 계산
	}

	scanf("%d", &m);//연체 요금 산정을 요구한 학생의 수
	for (i = 0; i < m; i++) {//연체 요금 산정을 요구한 학생의 학번을 inputid에 입력받기
		scanf("%d", &inputid[i]);
	}

	for (i = 0; i < m; i++) {
		flag = 0;//초기화
		printf("%d", inputid[i]);//일단 inputid에 있는 학번 출력
		for (j = 0; j < n; j++) {
			if (inputid[i] == l[j].studentid &&l[j].gapdate > 15) {//연체가 있는 학생은
				flag++;//연체가 없다면 flag는 0이다
				printf(" %d(%d)", l[j].bookid, (l[j].gapdate - 15) * 100);//책의 일련번호, 연체료 출력
			}
		}
		if (flag == 0) printf(" X");//연체가 없는 학생은 학번과 X를 출력
		printf("\n");
	}
}