#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct customer {//구조체 선언
	char id[5];
	char *name;
	char *phone;
}CUS;


int main() {
	CUS *st;
	int i, j, n;
	char tmp1[50], tmp2[20], targetid[5];

	scanf("%d", &n);

	st = (CUS *)malloc(n * sizeof(CUS));//입력받은 n만큼 구조체 동적할당

	for (i = 0; i < n; i++) {
		scanf("%s %s", tmp1, tmp2);//입력받기
		getchar();
		st[i].name = (char *)malloc(sizeof(char)*(strlen(tmp1) + 1));//입력받은 정보 동적할당 후 입력
		strcpy(st[i].name, tmp1);

		st[i].phone = (char *)malloc(sizeof(char)*(strlen(tmp2) + 1));//입력받은 정보 동적할당 후 입력
		strcpy(st[i].phone, tmp2);

		strcpy(st[i].id, tmp2 + 9);//전화번호 뒷자리 4자리 id에 복사
	}
	scanf("%s", targetid);

	for (i = 0; i < n; i++) {//타겟id와 같으면 그 구조체의 정보 출력
		if (strcmp(st[i].id, targetid) == 0) {
			printf("%s %s %d", st[i].name, st[i].phone, i + 1);
		}
	}
}

