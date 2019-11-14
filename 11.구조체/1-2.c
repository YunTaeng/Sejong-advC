#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

typedef struct student {//구조체 student
	char name[10];
	char studentid[11];
	char lastgrade;
}STUDENT;//typedef로 사용자 형정의

int main() {
	int i, j;
	STUDENT l[5];//5명입력받음
	char targetname[10];
	int targetidyear = 0, tmpidyear, flag = 0, targetnum;

	for (i = 0; i < 5; i++) {
		scanf("%s %s %c", l[i].name, l[i].studentid, &l[i].lastgrade);//5명 학생의 이름과 각 학생의 학번 및 지난학기 평균학점을 입력받기
	}
	scanf("%s", targetname);//처음에 입력받는 이름 저장해두기

	for (i = 0; i < 5; i++) {
		if (strcmp(targetname, l[i].name) == 0) {//입력받은 이름과 구조체의 이름이 같을경우
			targetnum = i;//배열의 몇번째인지 받아두기
			for (j = 0; j < 4; j++) {//입학년도를 targeidyear에 받아두기
				targetidyear *= 10;
				targetidyear += l[i].studentid[j] - '0';
			}
		}
	}
	for (i = 0; i < 5; i++) {
		if (i == targetnum) continue;//i가 targetnum이라면 같은사람을 비교하는 것이니 continue해준다
		tmpidyear = 0;
		for (j = 0; j < 4; j++) {//i를 바꿔가며 입학년도 받아두기
			tmpidyear *= 10;
			tmpidyear += l[i].studentid[j] - '0';
		}
		if (targetidyear == tmpidyear && l[targetnum].lastgrade == l[i].lastgrade) {//입학년도같고 학점도 같으면 출력
			printf(" %s\n", l[i].name);
			flag = 1;//조건이 맞는학생이 하나라도 있다면 flag=1
		}
	}
	if (flag == 0) printf("0");//flag가 0이라면 조건에 맞는 학생이 없다는 것이므로 0을 출력
}