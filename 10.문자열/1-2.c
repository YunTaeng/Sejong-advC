#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int strchange(char str[], char str2[]) {//문자열을 변경하여 비교하는 함수선언
	char str1[41], tmp;
	int i, j, k, num, n, flag, len;
	for (n = 1; n <= 10; n++) {//n을 바꿔가며 변경가능한지 알아보기
		strcpy(str1, str);//입력받은 문자열을 빈 문자열에 받아두기
		len = strlen(str1);//문자열 길이 받아두기
		i = 0;
		while (str1[i] != '\0') {//문자열의 끝까지
			if ('A' <= str1[i] && str1[i] <= 'Z') {//대문자일 경우 해당 대문자로부터 알파벳순으로 n번째 뒤 대문자
				str1[i] += n;
			}

			else if ('a' <= str1[i] && str1[i] <= 'z') {//소문자일 경우 해당 소문자로부터 알파벳순으로 n번째 앞 소문자
				str1[i] -= n;
			}

			else if ('0' <= str1[i] && str1[i] <= '9') {//숫자일 경우
				if ('0' <= str1[i + 1] && str1[i + 1] <= '9') { //두자리 숫자인지 확인
					num = (str1[i] - '0') * 10 + str1[i + 1] - '0';
					if (num >= 27) {//두자리 수 인데 27보다 크다면 그것은 두자리 숫자로 보면 안되고 한자리 수로 본다
						num = str1[i] - '0';
						flag = 1;//한자리수일때 flag=1
					}
					else flag = 2;//두자리수일때 flag=2
				}
				else {//한자리수
					num = str1[i] - '0';
					flag = 1;
				}

				tmp = 'A' + num - 1; //해당 숫자 번째의 알파벳 대문자를 tmp에 받아둠

				if (flag == 1) {//한자리 숫자일 경우
					len += n - 1;//문자열의 길이는 n-1만큼 길어짐
					for (j = 0; j < n - 1; j++) { //한칸씩 뒤로 미뤄서 n번의 숫자 번째의 알파벳 대문자가 들어갈 자리 마련
						for (k = len; k >= i + 1; k--) {
							str1[k + 1] = str1[k];
						}
					}
					for (j = 0; j < n; j++) {//해당 숫자 번째의 알파벳 대문자 n번 반복
						str1[i + j] = tmp;
					}
					i += n - 1;//i의 위치도 변경. 아래 i++이 있으니 주의

				}

				else if (flag == 2) {//두자리 수일 경우

					if (n == 1) {//만약 n이 1이면 뒤로 미루는것이 아닌 앞으로 땡겨야함. 그러므로 따로 설정 
						for (j = i + 1; j < len; j++) {//앞으로 땡김
							str1[j] = str1[j + 1];
						}
						str1[i] = tmp;
					}

					else {
						len += n - 2;//문자열의 길이가 n-2개 늘어남
						for (j = 0; j < n - 2; j++) {//한칸씩 뒤로 미뤄서 n번의 숫자 번째의 알파벳 대문자가 들어갈 자리 마련
							for (k = len; k >= i + 1; k--) {
								str1[k + 1] = str1[k];
							}
						}
						for (j = 0; j < n; j++) {//해당 숫자 번째의 알파벳 대문자 n번 반복
							str1[i + j] = tmp;
						}
						i += n - 1;//i의 위치도 변경. 아래 i++이 있으니 주의
					}

				}

			}

			else {
				str1[i] = ' ';//그 외는 공백으로 변경
			}
			i++;
		}
		str1[len] = '\0';
		if (strcmp(str1, str2) == 0) {//바뀐 문자열과 비교대상인 문자열을 비교하여 같으면 1을 리턴
			return 1;
		}
	}
	return 0;//같지않으면 0을 리턴
}

int main() {
	char str1[41], str2[41];
	int  flag1, flag2;

	gets(str1);//문자열 받아두기(공백이 있을수 있으니 gets함수 사용)
	gets(str2);

	flag1 = strchange(str1, str2);//str1을 str2로 변경가능한지
	flag2 = strchange(str2, str1);//str2을 str1로 변경가능한지

	if (flag1 == 1 && flag2 == 0) printf("1"); //A→B로 변경가능하면 1
	else if (flag1 == 0 && flag2 == 1) printf("2");//B→A로 변경가능하면 2
	else if (flag1 == 1 && flag2 == 1) printf("3");//둘 다 가능하면 3
	else printf("0"); //변경불가능하면 0

}