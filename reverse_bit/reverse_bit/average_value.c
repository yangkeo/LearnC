#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a = 0;
	int b = 0;
	float tmp = 0;
	int max = 0;
	int min = 0;
	float average = 0;
	printf("������������\n");
	scanf("%d %d", &a, &b);
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	tmp = (max - min) / 2.0;
	average = tmp + min;
	printf("%d �� %d ƽ��ֵΪ%f\n", a, b, average);
	printf("\n");
	system("pause");
	return 0;
}