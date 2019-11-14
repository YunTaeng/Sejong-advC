#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[1001], *word[100], *p, *q; //최대길이 1000인 문자열
	int wordcnt, i, j, k, cnt = 0, similar;
	char a[101], b[101];

	gets(str);//공백을 포함하는 문자열 입력받기
	scanf("%d", &k);

	word[cnt] = str;//word포인터의 처음은 배열str의 맨앞
	cnt++;

	for (i = 0; str[i] != '\0'; i++) {//스페이스바가 쳐질때 마다 word포인터에 str[i+1]의 주소를 입력
		if (str[i] == ' ') {
			str[i] = '\0';
			word[cnt++] = &str[i + 1];//스페이스바 다음이 다음 단어의 시작이므로
		}
	}
	wordcnt = cnt;//단어의 개수 받아놓기

	for (i = 0; i < wordcnt; i++) {//맨처음부터 단어의 총개수까지
		for (j = i + 1; j < wordcnt; j++) {//i의 다음의 것들을 비교
			if (strlen(word[i]) < strlen(word[j])) { //길이가 다를 경우 길이가 긴 것을 앞으로
				p = word[i];
				word[i] = word[j];
				word[j] = p;
			}
			else if (strlen(word[i]) == strlen(word[j]) && (strcmp(word[i], word[j]) > 0)) {//길이가 같을경우 사전 순으로
				p = word[i];
				word[i] = word[j];
				word[j] = p;
			}
		}
	}
	printf("%s\n", word[k - 1]);//K번째 위치의 단어를 출력

	//비교의 기준은 word[k-1]이 된다

	for (i = 0; i < wordcnt; i++) {
		if (i == k - 1) continue;//같은것과는 비교하지 않게

		strcpy(a, word[k - 1]);//a에는 기준인 word[k-1]을 복사
		strcpy(b, word[i]);//b에는 비교대상인 word[i]를 복사

		cnt = 0;//cnt초기화

		for (p = a; *p; p++) { //배열을 돌며 같은것이 있나 찾기
			for (q = b; *q; q++) {
				if (*p == *q) {//같을경우 cnt++을 함. 
					cnt++;
					*q = ' ';// 한번 세었으므로 *q는 공백으로 바꿈.*q 뒤의 같은 문자가 공백으로 바뀌지않게 break
					break;
				}
			}
		}
		if (strlen(word[k - 1]) > strlen(word[i])) similar = strlen(word[k - 1]) - cnt;//두 문자열중 긴것에서 cnt를 뺀 것을 similar이라함
		else similar = strlen(word[i]) - cnt;//similar이 -1이나 1이면 word[k-1]에서 한가지 문자를 추가하거나 빼면 만들수있다는뜻

		if (-1 <= similar && similar <= 1) printf("%s\n", word[i]);//비교대상이 조건에 부합하면 출력
	}
}