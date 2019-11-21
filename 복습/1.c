#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	char tmp1[101], tmp2[101], *p, *q, *k, *str1, *str2, *ans;
	int flag, num1, num2, sum, lena, lenb, longlen, flag2 = 0;

	scanf("%s", tmp1);
	scanf("%s", tmp2);

	lena = strlen(tmp1);
	lenb = strlen(tmp2);

	if (lena < lenb) longlen = lenb;
	else longlen = lena;

	str1 = (char *)malloc((lena + 1) * sizeof(char));
	str2 = (char *)malloc((lenb + 1) * sizeof(char));

	ans = (char *)malloc((longlen + 2) * sizeof(char));
	strcpy(str1, tmp1);
	strcpy(str2, tmp2);

	p = str1 + lena - 1;
	q = str2 + lenb - 1;
	k = ans;
	flag = 0;
	while (1) {
		if ('0' <= *p&&*p <= '9') {
			num1 = *p - '0';
		}
		else {
			num1 = 0;
		}
		if ('0' <= *q&&*q <= '9') {
			num2 = *q - '0';
		}
		else {
			num2 = 0;
		}

		if (num1 + num2 + flag > 9) {
			sum = num1 + num2 + flag - 10;
			flag = 1;
		}
		else {
			sum = num1 + num2 + flag;
			flag = 0;
		}
		*k = sum + '0';
		if (k - ans == longlen - 1 && flag == 1) {
			flag2 = 1;
		}
		k++;
		p--;
		q--;
		if (k - ans == longlen)break;
	}
	if (flag2 == 1) {
		*k = '1';
		for (p = ans + longlen; p >= ans; p--) {
			printf("%c", *p);
		}
	}

	else {
		for (p = ans + longlen - 1; p >= ans; p--) {
			printf("%c", *p);
		}
	}
	free(str1);
	free(str2);
	free(ans);
}