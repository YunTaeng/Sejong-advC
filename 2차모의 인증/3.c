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






