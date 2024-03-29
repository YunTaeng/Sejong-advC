#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

struct parking {
	int carnum;
	int studentid;
	char inouttime[40];//여기까진 기본적으로 입력받는정보
	int timepass;//이용시간
	int penalty;//부정이용자인지
	int pay;//주차요금
};


int main() {
	int i, j, k, n, m, intime, outtime, cnt = 0, flag, inputcarnum[100];
	struct parking l[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &l[i].carnum, &l[i].studentid);//차번호,학번입력받기
		gets(l[i].inouttime);//입출입시간 받아두기
	}

	for (i = 0; i < n; i++) {//inouttime의 ㅁㅁ:ㅁㅁ에서 :를 통하여 intime와 outtime을 구하기
		intime = 0;//초기화
		outtime = 0;
		for (j = 0;; j++) {
			if (l[i].inouttime[j] == ':') {//들어간 시간 :을 통하여 intime에 받아두기
				k = j - 2;
				while (k != j + 2) {//앞의 두자리를 더하고 60을 곱하고 뒤의 두자리 더하기
					if (k == j) intime *= 60;//시간은 60곱하기
					else if (k == j - 2 || k == j + 1) {
						intime += (l[i].inouttime[k] - '0') * 10 + l[i].inouttime[k + 1] - '0';
					}
					k++;
				}
				j++;//j가 :에 있는채로 브레이크 하면 안되므로 j++
				break;
			}

		}
		for (;; j++) {
			if (l[i].inouttime[j] == ':') {//나온 시간 :을 통하여 intime에 받아두기
				k = j - 2;
				while (k != j + 2) {
					if (k == j) outtime *= 60;//앞의 두자리를 더하고 60을 곱하고 뒤의 두자리 더하기
					else if (k == j - 2 || k == j + 1) {//시간은 60곱하기
						outtime += (l[i].inouttime[k] - '0') * 10 + l[i].inouttime[k + 1] - '0';
					}
					k++;
				}
				break;//시간을 다 받아뒀으면 브레이크로 끝내기
			}

		}
		l[i].timepass = outtime - intime;//이용시간 timepass에 받아두기
	}

	for (i = 0; i < n; i++) {
		flag = 0;//초기화
		for (j = 0; j < i; j++) {//학번이 같고 차번호가 다를경우(부정이용자)를 체크
			if (l[i].studentid == l[j].studentid && l[i].carnum != l[j].carnum) {
				flag++;
			}
		}
		if (flag != 0) {//부정이용자라면 
			for (j = 0; j < n; j++) {
				if (l[i].studentid == l[j].studentid) {
					l[j].penalty = 1;//penalty에 1로 표시
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (l[i].penalty == 1) l[i].pay = 100000;//부정이용자는 벌금100000원
		else {
			if (l[i].timepass <= 60) l[i].pay = 3000;//최초 1시간은 3000원
			else if (l[i].timepass <= 330) {//주차요금이 30000원을 넘지 않는경우
				l[i].pay = 3000;
				l[i].timepass -= 60;
				while (l[i].timepass > 0) {//기본인 1시간 3000원에 10분마다 1000원씩 추가
					l[i].timepass -= 10;
					l[i].pay += 1000;
				}
			}
			else l[i].pay = 30000;//이용시간이 330분 이상이라면 최대 주차요금인 30000원을 넘으므로
		}
	}

	scanf("%d", &m);//요금 산정 시 차량의 대수 몇대인지

	for (i = 0; i < m; i++) {
		scanf("%d", &inputcarnum[i]);//요금 산정 시 차량의 대수입력받기
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (inputcarnum[i] == l[j].carnum) printf("%d\n", l[j].pay);//입력받은 차번호와 l에의 차번호가 같으면 ㅣ의 구조체의 pay출력
		}
	}
}