#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct book {
	char *name;
	char *author;
	char date[9];
}BOOK;

void inputscore(struct book *st, int n) {
	struct book *p;
	char tmp[101];
	char tmp2[21];

	for (p = st; p < st + n; p++) {
		scanf("%s %s %s", tmp, tmp2, p->date);
		getchar();
		p->name = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
		strcpy(p->name, tmp);
		p->author = (char *)malloc((strlen(tmp2) + 1) * sizeof(char));
		strcpy(p->author, tmp2);
	}
}

int check(struct book st, char *str) {
	if (strncmp(st.date, str, 4) == 0) {
		return 0;
	}
	else return 1;
}

void sort(struct book *st, int n) {
	struct book *p, *q, tmp;

	for (p = st; p < st + n; p++) {
		for (q = p; q < st + n; q++) {
			if (strcmp(p->author, q->author) > 0) {
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
}

int main() {
	int n, i, j, cnt = 0;
	BOOK *st, *ans;
	char targetyear[5];
	scanf("%d", &n);
	getchar();
	st = (BOOK *)malloc(n * sizeof(BOOK));
	ans = (BOOK *)malloc(n * sizeof(BOOK));

	inputscore(st, n);


	gets(targetyear);

	for (i = 0; i < n; i++) {
		if (check(st[i], &targetyear) == 0) {
			ans[cnt++] = st[i];
		}
	}

	sort(ans, cnt);

	for (i = 0; i < cnt; i++) {
		printf("%s %s %s\n", ans[i].name, ans[i].author, ans[i].date);
	}
}