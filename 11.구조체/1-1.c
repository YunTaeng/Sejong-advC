#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

typedef struct student {
	char name[10];
	int studentid[11];
	char lastgrade;
}STUDENT;

int main() {
	int i;
	STUDENT l[5];
	char a[10];

	for (i = 0; i < 5; i++) {
		scanf("%s %s %c", l[i].name, l[i].studentid, &l[i].lastgrade);
	}
	scanf("%s", a);

	for (i = 0; i < 5; i++) {
		if (strcmp(a, l[i].name) == 0) {
			printf(" %s %c", l[i].studentid, l[i].lastgrade);
		}
	}

}