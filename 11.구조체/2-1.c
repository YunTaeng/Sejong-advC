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
	int i, j, n, cnt = 0, flag;
	int stdy, stdm, stdd;//기준이 되는 날짜(오늘날짜) 입력받기
	int tmpy, tmpm;//임시의 y와 m선언
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//평년일경우 월
	int leapmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//윤년일경우 월
	int msg[50];//메세지를 보낼 사람들 리스트

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


	for (i = 0; i < n; i++) {
		if (l[i].gapdate > 15) {//15일이 지났을경우 연체
			flag = 0;
			for (j = 0; j < cnt; j++) {//msg배열에 이미 있는지 
				if (l[i].studentid == msg[j]) flag++;
			}
			if (flag == 0) msg[cnt++] = l[i].studentid;//flag가 0일때 추가
		}
	}

	for (i = 0; i < cnt; i++) {//msg리스트 출력
		printf("%d\n", msg[i]);
	}
}