#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct student {
	char name[20];
	double s1;
	double s2;
	double s3;
	double sum;
	int rank;
}STUDENT;

void inputscore(struct student *st, int n) {
	struct student *p;

	for (p = st; p < st + n; p++) {
		scanf("%s %lf %lf %lf", p->name, &p->s1, &p->s2, &p->s3);
	}
}

void printranking(struct student *st, int n) {
	struct student *p, *q;

	for (p = st; p < st + n; p++) {
		p->sum = p->s1 + p->s2 + p->s3;
		p->rank = 1;
	}
	for (p = st; p < st + n; p++) {
		for (q = st; q < st + n; q++) {
			if (p->sum < q->sum) p->rank++;
		}
	}

	for (p = st; p < st + n; p++) {
		printf("%s %d\n", p->name, p->rank);
	}
}

int main() {
	int n;
	STUDENT *STU;

	scanf("%d", &n);

	STU = (STUDENT *)malloc(n * sizeof(STUDENT));

	inputscore(STU, n);

	printranking(STU, n);

}