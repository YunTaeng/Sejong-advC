#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct tourcity {//관광지 구조체 선언
	char sights[21];
	int pay;
	char inout;
	char startday[9];
	char cityname[21];
}TOURCITY;

int main() {
	TOURCITY **st, maxst;
	int n, i, j, *sightnum;
	char **citynames, tmp[101];

	scanf("%d", &n);//n입력받기
	getchar();

	citynames = (char **)malloc(sizeof(char *) * n);//입력받은n에 따라 도시 이름 동적할당
	if (citynames == NULL) {//메모리 동적할당이 실패하는 경우 Not Enough Memory.를 출력하고 종료
		printf("Not Enough Memory.");
		return -1;
	}
	sightnum = (int *)malloc(sizeof(int) * n);//입력받은n에 따라 도시의 관광지 수 배열 동적할당
	if (sightnum == NULL) {
		printf("Not Enough Memory.");
		return -1;
	}
	st = (TOURCITY **)malloc(sizeof(TOURCITY *) * n);//구조체 배열 동적할당
	if (st == NULL) {
		printf("Not Enough Memory.");
		return -1;
	}

	for (i = 0; i < n; i++) {
		scanf("%s", tmp);//임의의 문자열 입력받기
		citynames[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));//그 길이만큼 동적할당
		if (citynames[i] == NULL) {
			printf("Not Enough Memory.");
			return -1;
		}
		strcpy(citynames[i], tmp);//동적할당된 메모리에 tmp넣기
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &sightnum[i]);//입력받은n에 따라 도시의 관광지 수 입력받기
	}

	for (i = 0; i < n; i++) {
		st[i] = (TOURCITY *)malloc(sizeof(TOURCITY)* sightnum[i]); //관광지 개수를 입력받아 동적할당
		if (st[i] == NULL) {
			printf("Not Enough Memory");
			return -1;
		}
		for (j = 0; j < sightnum[i]; j++) {//동적할당된 구조체에 입력받기
			scanf("%s %d %c %s", st[i][j].sights, &st[i][j].pay, &st[i][j].inout, st[i][j].startday);
			strcpy(st[i][j].cityname, citynames[i]);//구조체에 도시이름도 입력하기
		}
	}

	maxst = st[0][0];
	for (i = 0; i < n; i++) {//관광지의 입장료가 제일 비싼 관광지를 찾는 코드
		for (j = 0; j < sightnum[i]; j++) {//입장료가 다르면
			if (maxst.pay < st[i][j].pay) {
				maxst = st[i][j];
			}
			else if (maxst.pay == st[i][j].pay) {//입장료가 같을 때
				if (strcmp(maxst.startday, st[i][j].startday) > 0) {//관광지 시작일이 제일 오래된 곳을
					maxst = st[i][j];
				}
			}
		}
	}

	printf("%s %s %d %s %c", maxst.cityname, maxst.sights, maxst.pay, maxst.startday, maxst.inout);//관광지의 입장료가 제일 비싼 관광지의 정보 출력

	for (i = 0; i < n; i++) {//메모리 해제
		free(citynames[i]);
		free(st[i]);
	}
	free(sightnum);
	free(citynames);
	free(st);
}