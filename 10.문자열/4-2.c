#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[101], *tmp[10]; //최대길이 100인 문자열
	int numcnt, i, j, cnt = 0, minflag[10] = { 0 };
	double num[10];

	gets(str);//공백을 포함하는 문자열 입력받기

	for (i = 0; str[i] != '\0'; i++) {//공백 지우기
		if (str[i] == ' ') {//공백이 있으면 공백을 지우고 한칸씩 앞으로 당김
			for (j = i; str[j] != '\0'; j++) {
				str[j] = str[j + 1];
			}
		}
	}
	tmp[cnt] = str;//숫자를 기호를 기준으로 tmp에 char형태로 저장. tmp의 처음값은 str의 맨앞
	cnt++;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '-') {//기호가 -일경우 minflag를 통해 체크하기
			minflag[cnt] = 1;
		}
		if ('0' > str[i] || str[i] > '9') {//str이 숫자가 아닐경우 tmp의 다음 배열에 넣음 => 숫자가 기호를 기준으로 나뉘어져 tmp에 따로 저장
			str[i] = '\0';
			tmp[cnt++] = &str[i + 1];
		}
	}
	numcnt = cnt;//기호에 따라 나눠진 숫자가 몇개인지 받아놓기

	for (i = 0; i < numcnt; i++) {//tmp에 받아놓은 char배열을 실수형 배열num에 넣기
		if (minflag[i] == 1) {
			num[i] = -(double)atoi(tmp[i]);//앞의 기호가 -라면 -로 바꿔서 넣기
		}
		else num[i] = (double)atoi(tmp[i]);
	}

	for (i = 0; i < numcnt; i++) {

		printf(" %.0lf", num[i]);//출력

	}
}
