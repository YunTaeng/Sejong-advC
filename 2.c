#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Complex {
	double real;
	double img;
	double value;
}COM;

COM add(COM a, COM b) {
	COM tmp;
	tmp.img = a.img + b.img;
	tmp.real = a.real + b.real;
	return tmp;
}

COM sub(COM a, COM b) {
	COM temp;
	temp.img = a.img - b.img;
	temp.real = a.real - b.real;
	return temp;
}

void abs_val(COM *a, COM *b, COM *c) {
	COM max, min;



	max = min = *a;

	if (max.value < b->value) max = *b;
	else if (min.value > b->value) min = *b;

	if (max.value < c->value) max = *c;
	else if (min.value > c->value) min = *c;

	*a = max;
	*b = min;
}

int main() {
	int m, n, k, cnt = 0, min, i, j;
	COM l[3], addr, subr;

	for (i = 0; i < 3; i++) {
		scanf("%lf %lf", &l[i].real, &l[i].img);
		l[i].value = l[i].real*l[i].real + l[i].img*l[i].img;
	}


	abs_val(&l[0], &l[1], &l[2]);

	addr = add(l[0], l[1]);
	subr = sub(l[0], l[1]);

	printf("%.1lf%+.1lfi\n", addr.real, addr.img);
	printf("%.1lf%+.1lfi", subr.real, subr.img);
}