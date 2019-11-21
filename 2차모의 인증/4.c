#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct student {
	int id;
	int s1;
	int s2;
	double avg;
}STUDENT;

int main() {
	STUDENT *l, *passl, tmp;
	int i, j, k, n, passnum = 0, tmpi;


	scanf("%d", &n);

	l = (STUDENT *)malloc(n * sizeof(STUDENT));
	passl = (STUDENT *)malloc(n * sizeof(STUDENT));

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &l[i].id, &l[i].s1, &l[i].s2);
		l[i].avg = l[i].s1*0.4 + l[i].s2*0.6;
	}

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (l[i].avg < l[j].avg) {
				tmp = l[i];
				l[i] = l[j];
				l[j] = tmp;
			}
		}
	}

	i = 0;
	while (passnum < n * 6 / 10) {
		passl[passnum] = l[i];
		passnum++;
		i++;
	}
	tmpi = i - 1;
	for (j = i; j < n; j++) {
		if (l[tmpi].avg == l[j].avg) {
			passl[passnum] = l[j];
			passnum++;
		}
	}
	i = passnum;

	for (j = i; j < n; j++) {
		for (k = j; k < n; k++) {
			if (l[j].s2 < l[k].s2) {
				tmp = l[k];
				l[k] = l[j];
				l[j] = tmp;
			}

		}
	}

	while (passnum < n * 8 / 10) {
		passl[passnum] = l[i];
		passnum++;
		i++;
	}
	tmpi = i - 1;
	for (j = i; j < n; j++) {
		if (l[tmpi].s2 == l[j].s2) {
			passl[passnum] = l[j];
			passnum++;
		}
	}

	for (i = 0; i < passnum; i++) {
		for (j = i; j < passnum; j++) {
			if (passl[i].id > passl[j].id) {
				tmp = passl[i];
				passl[i] = passl[j];
				passl[j] = tmp;
			}
		}
	}

	for (i = 0; i < passnum; i++) {
		printf("%d\n", passl[i].id);
	}

	free(l);
	free(passl);

}