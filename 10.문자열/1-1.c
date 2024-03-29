#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

int main() {
	char str[41], tmp;
	int len, n, i = 0, j, k, flag, num;

	scanf("%s", str);//문자열 입력받기

	scanf("%d", &n);//n입력받기
	len = strlen(str);//문자열의 길이 len에 받아두기

	while (str[i]) {//문자열의 끝까지
		if ('A' <= str[i] && str[i] <= 'Z') {//대문자일 경우 해당 대문자로부터 알파벳순으로 n번째 뒤 대문자
			str[i] += n;
		}

		else if ('a' <= str[i] && str[i] <= 'z') {//소문자일 경우 해당 소문자로부터 알파벳순으로 n번째 앞 소문자
			str[i] -= n;
		}

		else if ('0' <= str[i] && str[i] <= '9') {//숫자일 경우
			if ('0' <= str[i + 1] && str[i + 1] <= '9') { //두자리 숫자인지 확인
				num = (str[i] - '0') * 10 + str[i + 1] - '0';
				if (num >= 27) {//두자리 수 인데 27보다 크다면 그것은 두자리 숫자로 보면 안되고 한자리 수로 본다
					num = str[i] - '0';
					flag = 1;//한자리수일때 flag=1
				}
				else flag = 2;//두자리수일때 flag=2
			}
			else {//한자리수
				num = str[i] - '0';
				flag = 1;
			}

			tmp = 'A' + num - 1; //해당 숫자 번째의 알파벳 대문자를 tmp에 받아둠

			if (flag == 1) {//한자리 숫자일 경우
				len += n - 1;//문자열의 길이는 n-1만큼 길어짐
				for (j = 0; j < n - 1; j++) { //한칸씩 뒤로 미뤄서 n번의 숫자 번째의 알파벳 대문자가 들어갈 자리 마련
					for (k = len; k >= i + 1; k--) {
						str[k + 1] = str[k];
					}
				}
				for (j = 0; j < n; j++) {//해당 숫자 번째의 알파벳 대문자 n번 반복
					str[i + j] = tmp;
				}
				i += n - 1;//i의 위치도 변경. 아래 i++이 있으니 주의

			}

			else if (flag == 2) {//두자리 수일 경우

				if (n == 1) {//만약 n이 1이면 뒤로 미루는것이 아닌 앞으로 땡겨야함. 그러므로 따로 설정 
					len -= n;//문자열의 길이가 n(1)만큼 줄어듬
					for (j = i + 1; j < len; j++) {//앞으로 땡김
						str[j] = str[j + 1];
					}
					str[i] = tmp;
				}

				else {
					len += n - 2;//문자열의 길이가 n-2개 늘어남
					for (j = 0; j < n - 2; j++) {//한칸씩 뒤로 미뤄서 n번의 숫자 번째의 알파벳 대문자가 들어갈 자리 마련
						for (k = len; k >= i + 1; k--) {
							str[k + 1] = str[k];
						}
					}
					for (j = 0; j < n; j++) {//해당 숫자 번째의 알파벳 대문자 n번 반복
						str[i + j] = tmp;
					}
					i += n - 1;//i의 위치도 변경. 아래 i++이 있으니 주의
				}

			}

		}

		else {
			str[i] = ' ';//그 외는 공백으로 변경
		}
		i++;
	}

	printf("%s", str);//문자열 출력

}


