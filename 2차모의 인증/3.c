#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	char **y, *x, tmp[101], **tmpp,**p,**q;
	int n,i,j,*num,cnt,flag=0;

	scanf("%d %s", &n, tmp);
	getchar();

	x = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(x, tmp);
	
	y = (char**)malloc(n * sizeof(char *));
	num=(int *)malloc(n * sizeof(int));

	

	for (i = 0; i < n; i++) {
		gets(tmp);
		y[i] = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(y[i], tmp);
	}

	for (i = 0; i < n; i++) {
		cnt = 0;
		for (j = 0; y[i][j]; j++) {
			if (strncmp(x, &y[i][j], strlen(x)) == 0) {
				cnt++;
				j += strlen(x) - 1;
				flag = 1;
			}
			
		}
		num[i] = cnt;

	}

	for (p = y+n; p>y; p--) {
		for (q = y; q < p-1; q++) {
			if (num[q - y] < num[q - y + 1]) {
				tmpp = q;
				q = q + 1;
				q + 1 = tmpp;
			}
		}
	}


	if (flag = 0) {
		printf("NONE");
	}
	else {
		printf("%s", y[0]);

	}
	
}




/*
typedef struct list {//구조체 선언
	char id[6];
	int s1;
	int s2;
	double total;
}LIST;


int main() {
	LIST *l,*passl,tmp;
	int i, j, n, cnt, passnum = 0;
	double targetsc;

	scanf("%d", &n);//n입력받기

	l = (LIST *)malloc(n * sizeof(LIST));//입력받은 n만큼 구조체 동적할당
	passl= (LIST *)malloc(n * sizeof(LIST));//입력받은 n만큼 구조체 동적할당

	for (i = 0; i < n; i++) {
		scanf("%s %d %d", l[i].id, l[i].s1, l[i].s2);
		l[i].total = l[i].s1*0.4 + l[i].s2*0.6;
	}

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (l[i].total < l[j].total) {
				tmp = l[i];
				l[i] = l[j];
				l[j] = tmp;
			}
			if (l[i].total == l[j].total) {
				if (l[i].s2 < l[j].s2) {
					tmp = l[i];
					l[i] = l[j];
					l[j] = tmp;
				}
			}
		}
	}
	targetsc = l[n * 60 / 100].total;
	while (1) {
		

		
	}

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (strcmp(l[i].id, l[j].id) > 0) {
				tmp = l[i];
				l[i] = l[j];
				l[j] = tmp;
			}
		}
	}


	free(l);
}
*/






