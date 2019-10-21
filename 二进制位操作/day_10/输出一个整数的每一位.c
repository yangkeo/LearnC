#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MyPrint(int n)
{
	if (n != 0)
	{
		printf("%d", n%10);
		MyPrint(n / 10);
	}
}

int main(void)
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		MyPrint(n);
	}	

	printf("\n");
	system("pause");
	return 0;
}

