#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[1001], *word[100], *p; //최대길이 1000인 문자열
	int wordlen[100], i, j, k, cnt = 0;

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

	for (i = 0; i < cnt; i++) {//맨처음부터 cnt(=단어의 총개수,N )까지
		for (j = i + 1; j < cnt; j++) {//i번째 다음의 것들을 비교
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

	printf("%s", word[k - 1]);//K번째 위치의 단어를 출력
}