#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct customer {//구조체 선언
	char id[5];
	char *name;
	char *phone;
	struct customer *next;
}CUS;


int main() {
	CUS *st, *p, *q;
	int i, j, n, cnt;
	char tmp1[50], tmp2[20], targetid[5];

	scanf("%d", &n);//n입력받기

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

	for (i = 0; i < n; i++) {//구조체를 연결하는 코드
		st[i].next = NULL;//초기화
		for (j = i + 1; j < n; j++) {
			if (st[i].id[3] == st[j].id[3]) {//id의 마지막 번호가 같다면
				st[i].next = &st[j];  //다음 구조체의 주소를 구조체 포인터로 연결
				break; // 다음것만 연결 되어야 하므로 break
			}
		}
	}

	scanf("%s", targetid);//찾는 숫자 입력받기

	for (p = st; p < st + n; p++) {
		cnt = 1;
		if (p->id[3] == targetid[3]) {//구조체 연결고리의 시작이 되는 id찾기
			for (q = p; q; q = q->next) {//연결고리를 따라 cnt를 늘러가며 찾기
				if (strcmp(q->id, targetid) == 0) {//찾으면 출력하고 종료
					printf("%s %s %d\n", q->name, q->phone, cnt);
					return 0;
				}
				cnt++;
			}
		}
	}


	for (i = 0; i < n; i++) {//메모리 할당 해제
		free(st[i].name);
		free(st[i].phone);
	}
	free(st);
}

