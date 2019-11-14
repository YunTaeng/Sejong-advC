#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int cnt = 0, length = 0;
	char a[1000], *p = a, *q, *tmp;

	while (1) {
		scanf("%c", p);
		if (*p == '.' || *p == '!' || *p == '?') break; //입력의 종료는 ‘.’, ‘ ? ’, ‘!'이므로
		p++;
		length++; //기호를 제외한 배열의 길이 구하기
	}

	for (p = a + length - 1; p >= a; p--) {//기호 바로전의 배열부터 훑기. 
		if (*p == ' ') { //배열을 훑다가 스페이스바가 나오면 
			for (q = p + 1; q < p + cnt + 1; q++) { //훑은 단어의 길이(cnt)만큼만 정방향으로 문자열을 출력
				printf("%c", *q);
			}
			printf(" ");//스페이스바 출력
			cnt = 0;//cnt를 초기화
			continue; //출력을 했다면 cnt가 0인 상태에서 for문이 돌아야하니까 continue를 사용하여 아래 cnt++을 하지 않게 함
		}

		if (p == a) {//배열의 맨처음의 앞에는 스페이스바가 없으므로 마지막 단어는 따로 설정해 주어야 한다
			for (q = p; q <= p + cnt; q++) {//cnt만큼 출력
				printf("%c", *q);
			}
		}

		cnt++;//스페이스바가 나오지 않는다면 cnt를 세며 배열 계속 훑기

	}
	printf("%c", *(a + length)); //마지막 기호 출력
	return 0;
}